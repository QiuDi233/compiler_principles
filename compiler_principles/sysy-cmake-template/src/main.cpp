#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include "AST.h"
#include "RISCV.h"
#include "koopa.h"

using namespace std;

// 声明 lexer 的输入, 以及 parser 函数
// 为什么不引用 sysy.tab.hpp 呢? 因为首先里面没有 yyin 的定义
// 其次, 因为这个文件不是我们自己写的, 而是被 Bison 生成出来的
// 你的代码编辑器/IDE 很可能找不到这个文件, 然后会给你报错 (虽然编译不会出错)
// 看起来会很烦人, 于是干脆采用这种看起来 dirty 但实际很有效的手段
extern FILE *yyin;
extern int yyparse(unique_ptr<BaseAST> &ast);

int main(int argc, const char *argv[]) {
  // 解析命令行参数. 测试脚本/评测平台要求你的编译器能接收如下参数:
  // compiler 模式 输入文件 -o 输出文件
  assert(argc == 5);
  auto mode = argv[1];
  auto input = argv[2];
  auto output = argv[4];

  yyin = fopen(input, "r");
  assert(yyin);

  unique_ptr<BaseAST> ast;
  auto ret = yyparse(ast);
  assert(!ret);

  // 源代码转koopa IR
  if(string(mode) == "-koopa"){
    // dump AST
    freopen(output,"w",stdout);
    ast->Dump();
    cout << endl;
    return 0;
  }

  // 源代码转RISC-V
  if(string(mode) == "-riscv"){
    // 把IR存到一个临时的文件夹中
    // auto koopa_path = "debug/koopa.txt";
    auto koopa_path = "../koopa.txt";
    freopen(koopa_path,"w",stdout);
    ast->Dump();
    cout << endl;

    // 然后读到buf里
    FILE* koopa_file=fopen(koopa_path,"r");
    char *buf=(char *)malloc(1000000);
    fread(buf,1,100000,koopa_file);

    koopa_program_t program;
    koopa_error_code_t ret = koopa_parse_from_string(buf, &program);
    assert(ret == KOOPA_EC_SUCCESS); 
    koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    koopa_delete_program(program);

    // 处理 raw program
    freopen(output,"w",stdout);
    Visit(raw);
    
    koopa_delete_raw_program_builder(builder);

    return 0;
  }

  return 0;
}
