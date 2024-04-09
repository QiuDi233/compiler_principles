#pragma once
#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>

static int tmp_symbol_num = 0; // 记录临时符号 %0 %1...
static int block_num = 1;//数字由小变大表示从外到里 有几层block （其实后来发现名字没取好 更准确地表达应该是层数 而不是块数 (lv8.3 初始化由0改成1了，多了个全局的表)
static int block_id = 0;//有过多少个block 比如虽然是同一层的变量 但是是不同块 还是不能取相同的名字
static int have_returned = 0; //有的块里有多次返回 返回了一个的就后面不跑了
static int if_else_num = 0; //记录if else的层
static int while_num = 0; //记录while的层
static std::stack<int> while_stack; // 应对嵌套while

enum class DeclType { cst, var };
enum class VarDefType { ident,ident_initval };
enum class BlockItemType { decl, stmt };
enum class StmtType { lval, exp, block, ret, if_, if_else, while_, break_, continue_ };
enum class LOrExpType { land, lor_land };
enum class LAndExpType { eq, land_eq };
enum class EqExpType { rel, eq_rel };
enum class RelExpType { add, rel_add };
enum class AddExpType { mul, add_mul };
enum class MulExpType { unary, mul_unary };
enum class UnaryExpType { primary, unary, func };
enum class PrimaryExpType { exp, lval, number };
enum class ConstInitValType { const_exp, const_exp_list };
enum class InitValType { exp, init_val_list };
enum class LValType { ident, exp_list };
enum class FuncFParamType { var, arr };

#define CONST_TYPE 0
#define VAR_TYPE 1
#define ARRAY_TYPE 2
#define PARAM_ARRAY_TYPE 3

/*--------------------------符号表相关start---------------------------------*/
class Symbol
{
    public:
        int value; //这个常量的值
        std::string var_name; //这个变量的name 如%0
        int type; // 是变量还是常量 CONST_TYPE VAR_TYPE

        Symbol(int v){ //常量初始化
            type = CONST_TYPE;
            value = v;
        }
        Symbol(std::string name){ //变量初始化
            type = VAR_TYPE;
            var_name = name;
        }
        std::string symbol_info(){
            std::string res = "{";
            if(type==CONST_TYPE){
                res+=" CONST_TYPE; ";
                res+="value = "+std::to_string(value);
            }
            else if(type==VAR_TYPE){
                res+=" VAR_TYPE; ";
                res+="var_name = "+var_name;
            }
            res+="}";
            return res;
        }
};

// static std::map<std::string,Symbol*>symbol_map; //符号表
typedef std::map<std::string,Symbol*> SymbolTable;
static std::vector<SymbolTable>symbol_tables; //多个符号表

static Symbol* find_symbol(std::string l_val){
    // 在查询符号定义时, 先在当前符号表中查询, 如果找不到就去上一层中查询
    for(int i=symbol_tables.size()-1;i >= 0;i--){
        if(symbol_tables[i].count(l_val))
            return symbol_tables[i][l_val];
    }
    assert(false);
    return NULL;
}

static void delete_symbol_table(SymbolTable &symbol_table){
    // 删除符号表
    for(auto iter = symbol_table.begin();iter != symbol_table.end();iter++){
        delete iter->second;
    }
}

/*不知道为啥写成函数报错 (好像是依赖有问题)。。每次要用就从这里粘干脆 打印符号表用
    for(auto it = symbol_map->cbegin(); it != symbol_map->cend(); ++it){
        std::cout << "lval:" << it->first <<" | symbol : "<< it->second->symbol_info() << std::endl;
    }
*/

/*--------------------------符号表相关end---------------------------------*/

/*--------------------------函数相关start---------------------------------*/
class FuncInfo
{
    public:
        std::string func_name; //如 @half
        std::string return_type; // int or void
        std::vector<std::string> param_names; // @x这样的
        std::vector<std::string> param_types; // btype 不过应该都是int。。

        FuncInfo(std::string name, std::string ret_type){
            func_name = name;
            return_type = ret_type;
        }
        std::string funcinfo_info(){ //debug用
            std::cout<< "--func_name: " << func_name << ", return_type: " << return_type <<std::endl;
            return "";
        }

};
static std::map<std::string,FuncInfo*> func_table; 

/*--------------------------函数相关end---------------------------------*/

/*--------------------------AST相关start---------------------------------*/
// 所有 AST 的基类
class BaseAST {
 public:
  virtual ~BaseAST() = default;
  virtual std::string Dump() const = 0;
  virtual int CalExp() const { assert(false); return -1; }; //计算表达式的值 常数的时候有用

  virtual std::string get_ident() const { assert(false); return "Error"; }//前面没设计好。。LVal的ident取不出来。。加了个函数
  virtual std::string get_type() const { assert(false); return "Error"; }//前面没设计好。。FuncType的type取不出来。。加了个函数
  virtual const std::vector<std::unique_ptr<BaseAST>>& get_init_val_list() const {
    static const std::vector<std::unique_ptr<BaseAST>> emptyVector;
    assert(false);
    return emptyVector;
  }
  virtual std::string lval_dump() const { assert(false); return "Error"; };
  virtual std::string lval_param_dump() const { assert(false); return "Error"; };
};

// CompUnit ::= [CompUnit] (Decl | FuncDef);
class CompUnitAST : public BaseAST {
public:
  std::vector<std::unique_ptr<BaseAST>> func_def_list;
  std::vector<std::unique_ptr<BaseAST>> decl_list;

  std::string Dump() const override {
    // sysy库函数
    std::cout << "decl @getint(): i32" << std::endl;
    std::cout << "decl @getch(): i32" << std::endl;
    std::cout << "decl @getarray(*i32): i32" << std::endl;
    std::cout << "decl @putint(i32)" << std::endl;
    std::cout << "decl @putch(i32)" << std::endl;
    std::cout << "decl @putarray(i32, *i32)" << std::endl;
    std::cout << "decl @starttime()" << std::endl;
    std::cout << "decl @stoptime()" << std::endl << std::endl;
    FuncInfo *func_info = new FuncInfo("@getint", "int");
    func_table["getint"] = func_info;
    func_info = new FuncInfo("@getch", "int");
    func_table["getch"] = func_info;
    func_info = new FuncInfo("@getarray", "int");
    func_info->param_names.push_back("@x");
    func_info->param_types.push_back("*i32");
    func_table["getarray"] = func_info;
    func_info = new FuncInfo("@putint", "void");
    func_info->param_names.push_back("@x");
    func_info->param_types.push_back("i32");
    func_table["putint"] = func_info;
    func_info = new FuncInfo("@putch", "void");
    func_info->param_names.push_back("@x");
    func_info->param_types.push_back("i32");
    func_table["putch"] = func_info;
    func_info = new FuncInfo("@putarray", "void");
    func_info->param_names.push_back("@x");
    func_info->param_types.push_back("i32");
    func_info->param_names.push_back("@y");
    func_info->param_types.push_back("*i32");
    func_table["putarray"] = func_info;
    func_info = new FuncInfo("@starttime", "void");
    func_table["starttime"] = func_info;
    func_info = new FuncInfo("@stoptime", "void");
    func_table["stoptime"] = func_info;
    // sysy库函数end
    SymbolTable global_symbol;
    symbol_tables.push_back(global_symbol);
    for (auto&& decl : decl_list){
        decl->Dump();
    }
    std::cout << std::endl;
    for (auto&& func_def : func_def_list){
        func_def->Dump();
    }
    symbol_tables.pop_back();
    return "";
  }
};

// FuncDef     ::= FuncType IDENT "(" [FuncFParams] ")" Block;
class FuncDefAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> func_type;
  std::string ident;
  std::vector<std::unique_ptr<BaseAST>> func_f_params;
  std::unique_ptr<BaseAST> block;

  std::string Dump() const override {
    have_returned = 0;
    std::string func_name = "@" + ident;
    FuncInfo *func_info = new FuncInfo(func_name, func_type->get_type());
    std::cout << "fun ";
    std::cout << func_name << "(";
    bool f=false;
    for(auto&& param : func_f_params){
        if(f)
            std::cout<<",";
        std::string param_name = param->Dump();
        func_info->param_names.push_back(param_name);
        if(param->get_type()=="var"){
            func_info->param_types.push_back("i32");
        }
        if(param->get_type()=="arr"){
            func_info->param_types.push_back("*i32");
        }
        f=true;
    }
    func_table[ident] = func_info;
    std::cout<<")";
    func_type->Dump();
    std::cout << "{" << std::endl;
    std::cout << "%entry:" << std::endl;
    std::string block_res = block->Dump();
    if(block_res != "StmtType::ret"){
        if(func_type->get_type()=="void"){
            std::cout << "\tret" << std::endl;
        }
        if(func_type->get_type()=="int"){
            std::cout << "\tret 0" << std::endl;
        }
    }
    std::cout << "}"<<std::endl;
    return "";
  }
};

// FuncType    ::= "void" | "int";
class FuncTypeAST : public BaseAST {
public:
   std::string type;// "void" or "int"

   std::string Dump() const override {
    if(type=="int"){
        std::cout << ": i32 ";
        return "";
    }
    if(type=="void"){
        return "";
    }
    return "TypeError";
  }
  std::string get_type()const override {
    return type;
  }
};

// FuncFParam ::= BType IDENT ["[" "]" {"[" ConstExp "]"}];
class FuncFParamAST : public BaseAST {
public:
   FuncFParamType type;    
   std::string b_type;
   std::string ident;

    std::string Dump() const override {
        std::string param_name = "@" + ident;
        if(type==FuncFParamType::var){
            if(b_type=="int"){
                std::cout<< param_name << ": i32";
            }
            else{
                return "BtypeError";
            }
        }
        if(type==FuncFParamType::arr){
            std::cout<< param_name << ": *i32";
        }
        return param_name;
    }
    std::string get_type() const override {
        if(type==FuncFParamType::var){
            return "var";
        }
        if(type==FuncFParamType::arr){
            return "arr";
        }
        return "error";
    }

};

// Block::= "{" {BlockItem} "}";
class BlockAST : public BaseAST {
public:
    std::vector<std::unique_ptr<BaseAST>> block_item_list;
    std::string func_ident=""; //对于某个函数的定义中的block 该函数的名称

    std::string Dump() const override {
        // 进入新的block 要创建对应的符号表
        // have_returned = 0;//对于每个block 允许return一次(后来发现还是不行 因为有的ifelse语句没有{}括起来 改为进入函数 允许return一次 每次出if/else重新置为0)
        SymbolTable symbol_table;
        if(func_ident!=""){
            FuncInfo *func_info = func_table[func_ident];
            std::vector<std::string>param_names = func_info->param_names;
            std::vector<std::string>param_types = func_info->param_types;
            for(int i=0;i<param_names.size();++i){
                std::string name = param_names[i]; //@fx
                std::string type = param_types[i];
                std::string realloc_name = name;
                realloc_name[0] = '%'; //%x
                std::cout<< "\t" << realloc_name << " = alloc ";
                std::cout<< type << std::endl;
                std::cout<< "\tstore " << name << ", " <<realloc_name << std::endl;
                std::string ident = name.substr(1);//x
                Symbol *symbol = new Symbol(realloc_name);
                if(type=="*i32"){
                    symbol->type=PARAM_ARRAY_TYPE;
                }
                symbol_table[ident] = symbol;

            }
        }
        symbol_tables.push_back(symbol_table);
        block_num++;
        block_id++;//决定直接无脑++ 用来取名字而已 不重复就行
        std::string res = "";
        for (auto&& block_item : block_item_list){
            // std::cout <<block_item_list.size() << std::endl;
            if(have_returned){
                break;
            }
            res = block_item->Dump();
            if(res=="StmtType::ret"||res=="StmtType::break_"||res=="StmtType::continue_"){ //写到break和continue的时候加的 和前面的have_returned就返回有重复的逻辑好像 但是跑了没问题就这样吧
                break;
            }
        }
        delete_symbol_table(*(symbol_tables.rbegin()));
        symbol_tables.pop_back();
        block_num--;
        block_id++;
        return res;
    }
};

// BlockItem     ::= Decl | Stmt;
class BlockItemAST : public BaseAST {
public:
    BlockItemType type;
    std::unique_ptr<BaseAST> decl;
    std::unique_ptr<BaseAST> stmt;

    std::string Dump() const override {
        if(type == BlockItemType::decl){
            return decl->Dump();
        }
        if(type == BlockItemType::stmt){
            return stmt->Dump();
        }
        return "Error";
    }
};

/*Stmt ::= LVal "=" Exp ";"
       | [Exp] ";"
       | Block
       | "return" [Exp] ";";
       | "if" "(" Exp ")" Stmt;
       | "if" "(" Exp ")" Stmt "else" Stmt;
       | "while" "(" Exp ")" Stmt
       | "break" ";"
       | "continue" ";"
*/
class StmtAST : public BaseAST {
public:
    StmtType type;
    std::unique_ptr<BaseAST> lval;
    std::unique_ptr<BaseAST> exp;
    std::unique_ptr<BaseAST> block;
    std::unique_ptr<BaseAST> if_stmt;
    std::unique_ptr<BaseAST> else_stmt;
    std::unique_ptr<BaseAST> while_stmt;

    std::string Dump() const override {
        if(type == StmtType::lval){
            std::string ident = lval->get_ident();
            Symbol* lval_symbol = find_symbol(ident);
            if(lval_symbol->type==VAR_TYPE){
                std::string var_name = lval_symbol->var_name;
                std::string res = exp->Dump();
                std::cout << "\tstore " << res << ", "<<var_name << std::endl;
            }
            else if(lval_symbol->type==ARRAY_TYPE){
                std::string var_name = lval->lval_dump();
                std::string res = exp->Dump();
                std::cout << "\tstore " << res << ", "<< var_name << std::endl;
            }
            else if(lval_symbol->type==PARAM_ARRAY_TYPE){
                std::string var_name = lval->lval_param_dump();
                std::string res = exp->Dump();
                std::cout << "\tstore " << res << ", "<< var_name << std::endl;
            }
        }
        if(type == StmtType::ret){
            have_returned=1;
            std::string res = exp->Dump();
            std::cout << "\tret "<<res<< std::endl;
            return "StmtType::ret";
        }
        if(type == StmtType::exp){
            if(exp == nullptr){
                return "";
            }
            else{
                return exp->Dump();
            }
        }
        if(type == StmtType::block){
            return block->Dump();
        }
        if(type == StmtType::if_){
            std::string res = exp->Dump();
            std::string if_branch = "%then_" + std::to_string(if_else_num);
            std::string end = "\%end_" + std::to_string(if_else_num);
            if_else_num++;

            // if条件的判断部分
            std::cout << "\tbr " << res << ", " << if_branch <<", "<< end << std::endl;
            // if 语句的 if 分支
            std::cout<< if_branch <<":"<<std::endl;
            std::string if_stmt_res = if_stmt->Dump();
            have_returned = 0;
            if(if_stmt_res!="StmtType::ret"&&if_stmt_res!="StmtType::break_"&&if_stmt_res!="StmtType::continue_"){
                std::cout << "\tjump " << end << std::endl;
            }
            // if 语句之后的内容, if/else 分支的交汇处
            std::cout<< end <<":"<<std::endl;
            return "";
        }
        if(type == StmtType::if_else){
            std::string res = exp->Dump();
            std::string if_branch = "%then_" + std::to_string(if_else_num);
            std::string else_branch = "\%else_" + std::to_string(if_else_num);
            std::string end = "\%end_" + std::to_string(if_else_num);
            if_else_num++;

            // if条件的判断部分
            std::cout << "\tbr " << res << ", " << if_branch <<", "<< else_branch << std::endl;
            // if 语句的 if 分支
            std::cout<< if_branch <<":"<<std::endl;
            std::string if_stmt_res = if_stmt->Dump();
            have_returned = 0;
            if(if_stmt_res!="StmtType::ret"&&if_stmt_res!="StmtType::break_"&&if_stmt_res!="StmtType::continue_"){
                std::cout << "\tjump " << end << std::endl;
            }
            // if 语句的 else 分支
            std::cout<< else_branch <<":"<<std::endl;
            std::string else_stmt_res = else_stmt->Dump();
            have_returned = 0;
            if(else_stmt_res!="StmtType::ret"&&else_stmt_res!="StmtType::break_"&&else_stmt_res!="StmtType::continue_"){
                std::cout << "\tjump " << end << std::endl;
            }
            // if 语句之后的内容, if/else 分支的交汇处
            std::cout<< end <<":"<<std::endl;
            return "";
        }
        if(type==StmtType::while_){
            std::string while_entry = "%while_entry_" + std::to_string(while_num);
            std::string while_body = "%while_body_" + std::to_string(while_num);
            std::string while_end = "%while_end_" + std::to_string(while_num);
            while_stack.push(while_num);
            while_num++;
            std::cout << "\tjump " << while_entry << std::endl;
            //while_entry
            std::cout << while_entry << ":" << std::endl;
            std::string judge = exp->Dump();
            std::cout << "\tbr " << judge << ", " << while_body << ", " << while_end << std::endl;
            //while_body
            std::cout << while_body << ":" << std::endl;
            std::string while_stmt_res = while_stmt->Dump();
            have_returned = 0;
            if (while_stmt_res != "StmtType::ret"&&while_stmt_res!="StmtType::break_"&&while_stmt_res!="StmtType::continue_"){
                std::cout << "\tjump " << while_entry << std::endl;
            }
            std::cout << while_end << ":" << std::endl;
            while_stack.pop();
            return "";
        }
        if(type==StmtType::break_){
            int now_while_num = while_stack.top();
            std::string while_end = "%while_end_" + std::to_string(now_while_num);
            std::cout << "\tjump " << while_end << std::endl;
            have_returned=1;
            return "StmtType::break_";
        }
        if(type==StmtType::continue_){
            int now_while_num = while_stack.top();
            std::string while_entry = "%while_entry_" + std::to_string(now_while_num);
            std::cout << "\tjump " << while_entry << std::endl;
            have_returned=1;
            return  "StmtType::continue_";
        }
        return "type error";
    }

};


// Decl::= ConstDecl | VarDecl;
class DeclAST : public BaseAST {
public:
    DeclType type;
    std::unique_ptr<BaseAST> const_decl_exp;
    std::unique_ptr<BaseAST> var_decl_exp;

    std::string Dump() const override {
        if(type == DeclType::cst){
            return const_decl_exp->Dump();
        }
        if(type == DeclType::var){
            return var_decl_exp->Dump();
        }
        return "DeclAST Type Error";
    }

};

//ConstDecl::= "const" BType ConstDef {"," ConstDef} ";";
class ConstDeclAST : public BaseAST {
public:
    std::string b_type;
    std::vector<std::unique_ptr<BaseAST>> const_def_list;

    std::string Dump() const override {
        for (auto&& const_def : const_def_list){
            const_def->Dump();
        }
        return "";
    }

};

// ConstDef      ::= IDENT {"[" ConstExp "]"} "=" ConstInitVal;
// 在遇到常量声明语句时, 你应该遍历 AST, 直接算出语句右侧的 ConstExp 的值,
// 得到一个 32 位整数, 然后把这个常量定义插入到符号表中.
class ConstDefAST : public BaseAST {
public:
    std::string ident;
    std::unique_ptr<BaseAST> const_init_val;
    std::vector<std::unique_ptr<BaseAST>> const_exp_list;

    std::string Dump() const override {
        if(const_exp_list.size()==0){
            int v = const_init_val->CalExp();
            Symbol *symbol = new Symbol(v);
            SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
            (*symbol_map)[ident] = symbol; // 计算出来 存到符号表里
            return "";
        }
        else if(const_exp_list.size()==1){// 一维数组
            std::string var_name = "@" + ident + "_" + std::to_string(block_id);
            int arr_size = const_exp_list[0]->CalExp();
            if(block_num==1){//全局变量
                std::cout << "global " << var_name << " = alloc [i32, " << arr_size << "]"; // global @x = alloc [i32, 2], {1, 2}
                std::cout << ", {";
                const std::vector<std::unique_ptr<BaseAST>>* init_val_list = &const_init_val->get_init_val_list();
                int value = (*init_val_list)[0]->CalExp();
                std::cout<<value;
                for(int i=1;i<arr_size;++i){
                    if(i<(*init_val_list).size()){
                        value = (*init_val_list)[i]->CalExp();
                        std::cout<<", "<<value;
                    }
                    else{
                        std::cout<<", 0";
                    }
                }
                std::cout << "}" << std::endl;
            }
            else{
                std::cout << "\t" << var_name << " = alloc [i32, " << arr_size << "]" << std::endl; // @arr = alloc [i32, 2] 
                // 初始化
                const std::vector<std::unique_ptr<BaseAST>>* init_val_list = &const_init_val->get_init_val_list();
                for(int i=0;i<arr_size;++i){
                    if(i<(*init_val_list).size()){
                        /*%0 = getelemptr @arr, 0
                            store 1, %0*/
                        std::string var = "%" + std::to_string(tmp_symbol_num++);
                        int value = (*init_val_list)[i]->CalExp();
                        std::cout<< "\t" << var << " = getelemptr " << var_name << ", " << i <<std::endl;
                        std::cout<< "\tstore " << value << ", " << var << std::endl;
                    }
                    else{
                        std::string var = "%" + std::to_string(tmp_symbol_num++);
                        std::cout<< "\t" << var << " = getelemptr " << var_name << ", " << i <<std::endl;
                        std::cout<< "\tstore " << 0 << ", " << var << std::endl;
                    }
                }
            }
            Symbol *symbol = new Symbol(var_name);
            SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
            (*symbol_map)[ident] = symbol;
            return "";
        }
        else{// 多维数组没写
            assert(false);
            return "not completed";
        }
    }

};

//ConstInitVal  ::= ConstExp | "{" [ConstInitVal {"," ConstInitVal}] "}";
class ConstInitValAST : public BaseAST {
public:
    ConstInitValType type;
    std::unique_ptr<BaseAST> const_exp;
    std::vector<std::unique_ptr<BaseAST>> const_initval_list;

    std::string Dump() const override {
        if(const_initval_list.size()==0){
            return const_exp->Dump();
        }
        else{
            assert(false);
            return "not completed";
        }
    }

    const std::vector<std::unique_ptr<BaseAST>>& get_init_val_list() const override{
        return const_initval_list;
    }

    int CalExp() const override {
        return const_exp->CalExp();
    }
};

// ConstExp::= Exp;
class ConstExpAST : public BaseAST {
public:
    std::unique_ptr<BaseAST> exp;


    std::string Dump() const override {
        return exp->Dump();
    }

    int CalExp() const override {
        return exp->CalExp();
    }
};

// VarDecl::= BType VarDef {"," VarDef} ";";
class VarDeclAST : public BaseAST {
public:
    std::string b_type;
    std::vector<std::unique_ptr<BaseAST>> var_def_list;

    std::string Dump() const override {
        for (auto&& var_def : var_def_list){
            var_def->Dump();
        }
        return "";
    }
};

// VarDef        ::= IDENT ["[" ConstExp "]"]
//                 | IDENT ["[" ConstExp "]"] "=" InitVal;
class VarDefAST : public BaseAST {
public:
    VarDefType type;
    std::string ident;
    std::unique_ptr<BaseAST> init_val;
    std::vector<std::unique_ptr<BaseAST>> const_exp_list;

    std::string Dump() const override {
        if(const_exp_list.size()==0){
            if(type == VarDefType::ident){
                std::string var_name = "@" + ident + "_" + std::to_string(block_id);
                if(block_num==1){ // 全局变量
                    std::cout << "global " << var_name << " = alloc i32, zeroinit"<< std::endl;
                }
                else{
                    std::cout << "\t" << var_name << " = alloc i32" << std::endl;
                }
                Symbol *symbol = new Symbol(var_name);
                SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
                (*symbol_map)[ident] = symbol;
                return "";
            }
            if(type == VarDefType::ident_initval){
                std::string var_name = "@" + ident + "_" + std::to_string(block_id);
                if(block_num==1){ // 全局变量
                    int value = init_val->CalExp();
                    std::cout << "global " << var_name << " = alloc i32, " << std::to_string(value) << std::endl;
                }
                else{
                    std::cout << "\t" << var_name << " = alloc i32"<< std::endl;
                    std::string res = init_val->Dump();
                    std::cout << "\tstore " << res << ", "<< var_name << std::endl;
                }
                Symbol *symbol = new Symbol(var_name);
                SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
                (*symbol_map)[ident] = symbol; // 计算出来 存到符号表里
                return "";
            }
            return "type error";
        }
        else if(const_exp_list.size()==1){// 一维数组
            if(type == VarDefType::ident){
                std::string var_name = "@" + ident + "_" + std::to_string(block_id);
                int arr_size = const_exp_list[0]->CalExp();
                if(block_num==1){    
                    std::cout << "global " << var_name << " = alloc [i32, " << arr_size << "]"; // global @x = alloc [i32, 2], {0, 0}
                    std::cout << ", {" << "0";
                    for(int i=1;i<arr_size;++i){
                        std::cout<<", 0";
                    }
                    std::cout << "}" << std::endl;
                }
                else{
                    std::cout << "\t" << var_name << " = alloc [i32, " << arr_size << "]" << std::endl; // @arr = alloc [i32, 2] 
                    for(int i=0;i<arr_size;++i){
                        std::string var = "%" + std::to_string(tmp_symbol_num++);
                        std::cout<< "\t" << var << " = getelemptr " << var_name << ", " << i <<std::endl;
                        std::cout<< "\tstore " << 0 << ", " << var << std::endl;
                    }
                }
                Symbol *symbol = new Symbol(var_name);
                symbol->type=ARRAY_TYPE;
                SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
                (*symbol_map)[ident] = symbol;
                return "";
            }
            if(type == VarDefType::ident_initval){
                std::string var_name = "@" + ident + "_" + std::to_string(block_id);
                int arr_size = const_exp_list[0]->CalExp();
                if(block_num==1){
                    std::cout << "global " << var_name << " = alloc [i32, " << arr_size << "]"; // global @x = alloc [i32, 2], {1, 2}
                    std::cout << ", {";
                    const std::vector<std::unique_ptr<BaseAST>>* init_val_list = &init_val->get_init_val_list();
                    int value = (*init_val_list)[0]->CalExp();
                    std::cout<<value;
                    for(int i=1;i<arr_size;++i){
                        if(i<(*init_val_list).size()){
                            value = (*init_val_list)[i]->CalExp();
                            std::cout<<", "<<value;
                        }
                        else{
                            std::cout<<", 0";
                        }
                    }
                    std::cout << "}" << std::endl;
                }
                else{
                    std::cout << "\t" << var_name << " = alloc [i32, " << arr_size << "]" << std::endl; // @arr = alloc [i32, 2] 
                    // 初始化
                    const std::vector<std::unique_ptr<BaseAST>>* init_val_list = &init_val->get_init_val_list();
                    for(int i=0;i<arr_size;++i){
                        if(i<(*init_val_list).size()){
                            /*%0 = getelemptr @arr, 0
                                store 1, %0*/
                            std::string var = "%" + std::to_string(tmp_symbol_num++);
                            int value = (*init_val_list)[i]->CalExp();
                            std::cout<< "\t" << var << " = getelemptr " << var_name << ", " << i <<std::endl;
                            std::cout<< "\tstore " << value << ", " << var << std::endl;
                        }
                        else{
                            std::string var = "%" + std::to_string(tmp_symbol_num++);
                            std::cout<< "\t" << var << " = getelemptr " << var_name << ", " << i <<std::endl;
                            std::cout<< "\tstore " << 0 << ", " << var << std::endl;
                        }
                    }
                }
                Symbol *symbol = new Symbol(var_name);
                symbol->type=ARRAY_TYPE;
                SymbolTable *symbol_map = &(symbol_tables[block_num-1]);
                (*symbol_map)[ident] = symbol;
                return "";
            }
            return "type error";
        }
        else{ //多维的 没写
            assert(false);
            return "not completed";
        }
    }

};

// InitVal       ::= Exp | "{" [InitVal {"," InitVal}] "}";
class InitValAST : public BaseAST {
public:
    InitValType type;
    std::unique_ptr<BaseAST> exp;
    std::vector<std::unique_ptr<BaseAST>> init_val_list;

    std::string Dump() const override {
        if(init_val_list.size()==0){
            return exp->Dump();
        }
        else{
            assert(false);
            return "Error";
        }
    }
    const std::vector<std::unique_ptr<BaseAST>>& get_init_val_list() const override{
        return init_val_list;
    }
    int CalExp() const override {
        return exp->CalExp();
    }
};

// Exp::= LOrExp;
class ExpAST : public BaseAST {
public:
    std::unique_ptr<BaseAST> lor_exp;

    std::string Dump() const override {
        return lor_exp->Dump();
    }
    int CalExp() const override {
        return lor_exp->CalExp();
    }

};

// LOrExp::= LAndExp | LOrExp "||" LAndExp;
class LOrExpAST : public BaseAST {
public:
    LOrExpType type;
    std::string op;
    std::unique_ptr<BaseAST> land_exp;
    std::unique_ptr<BaseAST> lor_exp;

    std::string Dump() const override {
        if(type == LOrExpType::land){
            return land_exp->Dump();
        }
        if(type == LOrExpType::lor_land){
            if(op=="||"){ // a||b等价于(a!=0)|(b!=0)
                // // a!=0
                // std::string res11 = lor_exp->Dump();
                // std::string res12 = "0";
                // std::string var1 = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var1<<" = ne "<<res11<<", "<<res12 << std::endl;
                // tmp_symbol_num++;

                // // b!=0
                // std::string res21 = land_exp->Dump();
                // std::string res22 = "0";
                // std::string var2 = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var2<<" = ne "<<res21<<", "<< res22 << std::endl;
                // tmp_symbol_num++;

                // std::string res1 = var1;
                // std::string res2 = var2;
                // std::string var = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var<<" = or "<<res1<<", "<< res2 << std::endl;
                // tmp_symbol_num++;
                // return var;

                // 改为带逻辑短路的
                /*
                int result = 1;
                if (lhs == 0) {
                result = rhs != 0;
                }
                // 表达式的结果即是 result
                */
                std::string lhs = lor_exp->Dump();
                std::string if_branch = "%then__" + std::to_string(if_else_num);
                std::string else_branch = "\%else__" + std::to_string(if_else_num);
                std::string end = "\%end__" + std::to_string(if_else_num);
                if_else_num++;
                //存result=1
                std::string result = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << result << " = alloc i32" << std::endl;
                // if lhs==0 跳到else
                std::cout << "\tbr " << lhs << ", " << if_branch << ", " << else_branch << std::endl;
                // then:
                std::cout << if_branch << ":" << std::endl;
                std::cout << "\tstore 1, " << result << std::endl;
                std::cout << "\tjump " << end << std::endl;
                // else:
                std::cout << else_branch << ":" << std::endl;
                std::string tmp_var = "%" + std::to_string(tmp_symbol_num++);//rhs != 0
                std::string rhs = land_exp->Dump();
                std::cout << '\t' << tmp_var << " = ne " << rhs << ", 0" << std::endl;
                std::cout << "\tstore " << tmp_var << ", " << result << std::endl;
                std::cout << "\tjump " << end << std::endl;
                // end: 返回表达式的结果result
                std::cout << end << ":" << std::endl;
                std::string res = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << res << " = load " << result << std::endl;
                return res;
            }
            return "LOrExpAST OP Error";
        }
        return "LOrExpAST TypeError";
    }

    int CalExp() const override {
        if(type == LOrExpType::land){
            return land_exp->CalExp();
        }
        if(type == LOrExpType::lor_land){
            int res1 = lor_exp->CalExp();
            if(res1!=0){
                return 1; //逻辑短路
            }
            int res2 = land_exp->CalExp();
            return (res2!=0);
        }
        assert(false);
        return -1;
    }
};

// LAndExp::= EqExp | LAndExp "&&" EqExp;
class LAndExpAST : public BaseAST {
public:
    LAndExpType type;
    std::string op;
    std::unique_ptr<BaseAST> eq_exp;
    std::unique_ptr<BaseAST> land_exp;

    std::string Dump() const override {
        if(type == LAndExpType::eq){
            return eq_exp->Dump();
        }
        if(type == LAndExpType::land_eq){
            if(op=="&&"){ // a&&b等价于(a!=0)&(b!=0)
                // // a!=0
                // std::string res11 = land_exp->Dump();
                // std::string res12 = "0";
                // std::string var1 = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var1<<" = ne "<<res11<<", "<<res12<< std::endl;
                // tmp_symbol_num++;

                // // b!=0
                // std::string res21 = eq_exp->Dump();
                // std::string res22 = "0";
                // std::string var2 = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var2<<" = ne "<<res21<<", "<<res22<< std::endl;
                // tmp_symbol_num++;

                // std::string res1 = var1;
                // std::string res2 = var2;
                // std::string var = "%" + std::to_string(tmp_symbol_num);
                // std::cout<<"\t"<<var<<" = and "<<res1<<", "<<res2 << std::endl;
                // tmp_symbol_num++;
                // return var;

                // 改为带逻辑短路的
                /*
                int result = 0;
                if (lhs == 1) {
                result = rhs != 0;
                }
                // 表达式的结果即是 result
                */
                std::string lhs = land_exp->Dump();
                std::string if_branch = "%then__" + std::to_string(if_else_num);
                std::string else_branch = "\%else__" + std::to_string(if_else_num);
                std::string end = "\%end__" + std::to_string(if_else_num);
                if_else_num++;
                //存result=1
                std::string result = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << result << " = alloc i32" << std::endl;
                // if lhs==1 跳到if
                std::cout << "\tbr " << lhs << ", " << if_branch << ", " << else_branch << std::endl;
                // then:
                std::cout << if_branch << ":" << std::endl;  
                std::string tmp_var = "%" + std::to_string(tmp_symbol_num++);//rhs != 0
                std::string rhs = eq_exp->Dump();
                std::cout << '\t' << tmp_var << " = ne " << rhs << ", 0" << std::endl;
                std::cout << "\tstore " << tmp_var << ", " << result << std::endl;
                std::cout << "\tjump " << end << std::endl;
                // else:
                std::cout << else_branch << ":" << std::endl;
                std::cout << "\tstore 0, " << result << std::endl;
                std::cout << "\tjump " << end << std::endl;
                // end: 返回表达式的结果result
                std::cout << end << ":" << std::endl;
                std::string res = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << res << " = load " << result << std::endl;
                return res;
            }
            return "LAndExpAST OP Error";
        }
        return "LAndExpAST TypeError";
    }

    int CalExp() const override {
        if(type == LAndExpType::eq){
            return eq_exp->CalExp();
        }
        if(type == LAndExpType::land_eq){
            int res1 = land_exp->CalExp();
            if(res1==0){
                return 0; //逻辑短路
            }
            int res2 = eq_exp->CalExp();
            return (res2!=0);
        }
        assert(false);
        return -1;
    }
};

// EqExp::= RelExp | EqExp ("==" | "!=") RelExp;
class EqExpAST : public BaseAST {
public:
    EqExpType type;
    std::string op;
    std::unique_ptr<BaseAST> rel_exp;
    std::unique_ptr<BaseAST> eq_exp;

    std::string Dump() const override {
        if(type == EqExpType::rel){
            return rel_exp->Dump();
        }
        if(type == EqExpType::eq_rel){
            if(op=="=="){
                std::string res1 = eq_exp->Dump();
                std::string res2 = rel_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = eq "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op=="!="){
                std::string res1 = eq_exp->Dump();
                std::string res2 = rel_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = ne "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            return "EqExpAST OP Error";
        }
        return "EqExpAST TypeError";
    }

    int CalExp() const override {
        if(type == EqExpType::rel){
            return rel_exp->CalExp();
        }
        if(type == EqExpType::eq_rel){
            int res1 = eq_exp->CalExp();
            int res2 = rel_exp->CalExp();
            if(op=="=="){
                return (res1==res2);
            }
            if(op=="!="){
                return (res1!=res2);
            }
            assert(false);
            return -1;
        }
        assert(false);
        return -1;
    }
};

// RelExp::= AddExp | RelExp ("<" | ">" | "<=" | ">=") AddExp;
class RelExpAST : public BaseAST {
public:
    RelExpType type;
    std::string op;
    std::unique_ptr<BaseAST> add_exp;
    std::unique_ptr<BaseAST> rel_exp;

    std::string Dump() const override {
        if(type == RelExpType::add){
            return add_exp->Dump();
        }
        if(type == RelExpType::rel_add){
            if(op=="<"){
                std::string res1 = rel_exp->Dump();
                std::string res2 = add_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = lt "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op==">"){
                std::string res1 = rel_exp->Dump();
                std::string res2 = add_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = gt "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op=="<="){
                std::string res1 = rel_exp->Dump();
                std::string res2 = add_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = le "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op==">="){
                std::string res1 = rel_exp->Dump();
                std::string res2 = add_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = ge "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            return "Error";
        }
        assert(false);
        return "Error";
    }

    int CalExp() const override {
        if(type == RelExpType::add){
            return add_exp->CalExp();
        }
        if(type == RelExpType::rel_add){
            int res1 = rel_exp->CalExp();
            int res2 = add_exp->CalExp();
            if(op=="<"){
                return (res1<res2);
            }
            if(op==">"){
                return (res1>res2);
            }
            if(op=="<="){
                return (res1<=res2);
            }
            if(op==">="){
                return (res1>=res2);
            }
            assert(false);
            return -1;
        }
        assert(false);
        return -1;
    }
};

// AddExp::= MulExp | AddExp ("+" | "-") MulExp;
class AddExpAST : public BaseAST {
public:
    AddExpType type;
    std::string op;
    std::unique_ptr<BaseAST> mul_exp;
    std::unique_ptr<BaseAST> add_exp;

    std::string Dump() const override {
        if(type == AddExpType::mul){
            return mul_exp->Dump();
        }
        if(type == AddExpType::add_mul){
            if(op=="+"){
                std::string res1 = add_exp->Dump();
                std::string res2 = mul_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = add "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op=="-"){
                std::string res1 = add_exp->Dump();
                std::string res2 = mul_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = sub "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            return "AddExpAST OP Error";
        }
        return "AddExpAST TypeError";
    }

    int CalExp() const override {
        if(type == AddExpType::mul){
            return mul_exp->CalExp();
        }
        if(type == AddExpType::add_mul){
            int res1 = add_exp->CalExp();
            int res2 = mul_exp->CalExp();
            if(op=="+"){
                return (res1+res2);
            }
            if(op=="-"){
                return (res1-res2);
            }
            assert(false);
            return -1;
        }
        assert(false);
        return -1;
    }

};

// MulExp::= UnaryExp | MulExp ("*" | "/" | "%") UnaryExp;
class MulExpAST : public BaseAST {
public:
    MulExpType type;
    std::string op;
    std::unique_ptr<BaseAST> unary_exp;
    std::unique_ptr<BaseAST> mul_exp;

    std::string Dump() const override {
        if(type == MulExpType::unary){
            return unary_exp->Dump();
        }
        if(type == MulExpType::mul_unary){
            if(op=="*"){
                std::string res1 = mul_exp->Dump();
                std::string res2 = unary_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = mul "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op=="/"){
                std::string res1 = mul_exp->Dump();
                std::string res2 = unary_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = div "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(op=="%"){
                std::string res1 = mul_exp->Dump();
                std::string res2 = unary_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = mod "<<res1<<", "<<res2 << std::endl;
                tmp_symbol_num++;
                return var;
            }
            return "MulExpAST OP Error,op:"+op;
        }
        return "MulExpAST TypeError";
    }

    int CalExp() const override {
        if(type == MulExpType::unary){
            return unary_exp->CalExp();
        }
        if(type == MulExpType::mul_unary){
            int res1 = mul_exp->CalExp();
            int res2 = unary_exp->CalExp();
            if(op=="*"){
                return (res1*res2);
            }
            if(op=="/"){
                return (res1/res2);
            }
            if(op=="%"){
                return (res1%res2);
            }
            assert(false);
            return -1;
        }
        assert(false);
        return -1;
    }
};

// UnaryExp::= PrimaryExp 
//            | UnaryOp UnaryExp;
//            | IDENT "(" [FuncRParams] ")"
class UnaryExpAST : public BaseAST {
public:
    UnaryExpType type;
    std::unique_ptr<BaseAST> primary_exp;
    std::unique_ptr<BaseAST> unary_exp;
    std::string ident;
    std::vector<std::unique_ptr<BaseAST>> func_r_params;
    std::string unary_op;

    std::string Dump() const override {
        if(type == UnaryExpType::primary){
            return primary_exp->Dump();
        }
        if(type == UnaryExpType::unary){
            if(unary_op=="+"){
                return unary_exp->Dump();
            }
            if(unary_op=="-"){
                std::string res = unary_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num); //返回的临时变量 写在左边的那个
                std::cout<<"\t"<<var<<" = sub 0, "<<res << std::endl;
                tmp_symbol_num++;
                return var;
            }
            if(unary_op=="!"){
                std::string res = unary_exp->Dump();
                std::string var = "%" + std::to_string(tmp_symbol_num);
                std::cout<<"\t"<<var<<" = eq "<<res<<", 0" << std::endl;
                tmp_symbol_num++;
                return var;
            }
            return "UnaryExpAST OP Error";
        }
        if(type == UnaryExpType::func){
            std::string name = func_table[ident]->func_name;
            std::string param_string = "";
            bool f=false;
            for (auto&& param : func_r_params){
                if(f)
                    param_string += ",";
                param_string += (param->Dump());
                f=true;
            }
            std::string func = name + "(" + param_string + ")"; //@half(10)
            if(func_table[ident]->return_type=="int"){
                std::string res = "%" + std::to_string(tmp_symbol_num++);
                std::cout<< "\t" << res << " = ";
                std::cout<< "call " << func <<std::endl;
                return res;
            }
            std::cout<< "\tcall " << func <<std::endl;
            return "";

        }
        return "UnaryExpAST TypeError";
    }

    int CalExp() const override {
        if(type == UnaryExpType::primary){
            return primary_exp->CalExp();
        }
        if(type == UnaryExpType::unary){
            int res1 = unary_exp->CalExp();
            if(unary_op=="+"){
                return res1;
            }
            if(unary_op=="-"){
                return -res1;
            }
            if(unary_op=="!"){
                return !res1;
            }
            assert(false);
            return -1;
        }
        assert(false);
        return -1;
    }
};



// PrimaryExp  ::= "(" Exp ")" | LVal | Number;
class PrimaryExpAST : public BaseAST {
public:
    PrimaryExpType type;
    std::unique_ptr<BaseAST> exp;
    std::unique_ptr<BaseAST> lval;
    int number;

    std::string Dump() const override {
        // std::cout <<"debug3" << std::endl;
        if(type == PrimaryExpType::exp){
            // exp->Dump();
            return exp->Dump();
        }
        if(type == PrimaryExpType::number){
            // std::cout <<"debug4" << std::endl;
            return std::to_string(number);
        }
        if(type == PrimaryExpType::lval){
            return lval->Dump();
        }
        return "PrimaryExpAST TypeError";
    }

    int CalExp() const override {
        if(type == PrimaryExpType::exp){
            return exp->CalExp();
        }
        if(type == PrimaryExpType::number){
            return number;
        }
        if(type == PrimaryExpType::lval){
            return lval->CalExp();
        }
        assert(false);
        return -1;
    }

};

// LVal::= IDENT | ["[" Exp "]"];
class LValAST : public BaseAST {
public:
    LValType type;
    std::string ident;
    std::vector<std::unique_ptr<BaseAST>> exp_list;

    std::string lval_dump() const override { // 给数组赋值用
        Symbol* lval_symbol = find_symbol(ident);// 数组名字 当变量存了
        if (lval_symbol == nullptr) {
            std::cout << "LValAST Symbol not found for key: " << ident << std::endl;
        }
        std::string res1 = "%" + std::to_string(tmp_symbol_num++);
        std::string value = exp_list[0]->Dump();
        std::cout<< "\t" << res1 << " = getelemptr " << lval_symbol->var_name << ", " << value <<std::endl;
        return res1;
    }
    std::string lval_param_dump() const override { // 给函数参数中的数组赋值用
        Symbol* lval_symbol = find_symbol(ident);// 数组名字 当变量存了
        if (lval_symbol == nullptr) {
            std::cout << "LValAST Symbol not found for key: " << ident << std::endl;
        }
        std::string value = exp_list[0]->Dump();
        std::string res0 = "%" + std::to_string(tmp_symbol_num++);
        std::string res1 = "%" + std::to_string(tmp_symbol_num++);
        std::cout<< "\t" << res0 << " = load " << lval_symbol->var_name << std::endl;
        std::cout<< "\t" << res1 << " = getptr " << res0 << ", " << value <<std::endl;
        return res1;
    }

    std::string Dump() const override {
        if(exp_list.size()==0){
            Symbol* lval_symbol = find_symbol(ident);
            if (lval_symbol == nullptr) {
                std::cout << "LValAST Symbol not found for key: " << ident << std::endl;
            }
            if(lval_symbol->type==CONST_TYPE){
                return std::to_string(lval_symbol->value);
            }
            if(lval_symbol->type==VAR_TYPE){
                std::string res = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << res << " = load " << lval_symbol->var_name << std::endl;
                return res;
            }
            if(lval_symbol->type==ARRAY_TYPE){
                /* 传递数组参数相当于传递其第一个元素的地址
                    %2 = getelemptr @arr, 0*/
                std::string res = "%" + std::to_string(tmp_symbol_num++);
                std::cout << '\t' << res << " = getelemptr " << lval_symbol->var_name << ", 0" << std::endl;
                return res;
            }
            if(lval_symbol->type==PARAM_ARRAY_TYPE){
                std::string res0 = "%" + std::to_string(tmp_symbol_num++);
                std::cout<< "\t" << res0 << " = load " << lval_symbol->var_name << std::endl;
                // std::string res1 = "%" + std::to_string(tmp_symbol_num++);
                // std::cout<< "\t" << res1 << " = getptr " << res0 << ", " << 0 <<std::endl;
                // std::string res2 = "%" + std::to_string(tmp_symbol_num++);
                // std::cout<< "\t" << res2 << " = load " << res1 << std::endl;
                return res0;
            }
            return "LVal Type Error";
        }
        else{
            if(exp_list.size()==1){
                /* %5 = getelemptr @arr, 2
                %6 = load %5
                ret %6*/
                Symbol* lval_symbol = find_symbol(ident);// 数组名字 当变量存了
                if (lval_symbol == nullptr) {
                    std::cout << "LValAST Symbol not found for key: " << ident << std::endl;
                }
                if(lval_symbol->type==ARRAY_TYPE){
                    std::string res1 = "%" + std::to_string(tmp_symbol_num++);
                    std::string value = exp_list[0]->Dump();
                    std::cout<< "\t" << res1 << " = getelemptr " << lval_symbol->var_name << ", " << value <<std::endl;
                    std::string res2 = "%" + std::to_string(tmp_symbol_num++);
                    std::cout<< "\t" << res2 << " = load " << res1 << std::endl;
                    return res2;
                }
                else if(lval_symbol->type==PARAM_ARRAY_TYPE){
                    /*%0 = load %arr
                    %1 = getptr %0, 1
                    %2 = load %1*/
                    std::string value = exp_list[0]->Dump();
                    std::string res0 = "%" + std::to_string(tmp_symbol_num++);
                    std::cout<< "\t" << res0 << " = load " << lval_symbol->var_name << std::endl;
                    std::string res1 = "%" + std::to_string(tmp_symbol_num++);
                    std::cout<< "\t" << res1 << " = getptr " << res0 << ", " << value <<std::endl;
                    std::string res2 = "%" + std::to_string(tmp_symbol_num++);
                    std::cout<< "\t" << res2 << " = load " << res1 << std::endl;
                    return res2;
                }
                else{
                    return "error";
                }
            }
            else{ //多维的没写
                assert(false);
                return "not completed";
            }
        }
    }

    int CalExp() const override {
        // 查表
        SymbolTable symbol_map = symbol_tables[block_num-1];
        Symbol* lval_symbol = symbol_map[ident];

        // 检查指针是否为 nullptr，避免访问空指针
        if (lval_symbol == nullptr) {
            std::cout << "LValAST Symbol not found for key: " << ident << std::endl;
        }
        assert(lval_symbol->type==CONST_TYPE);
        return lval_symbol->value;
    }

    std::string get_ident() const override{
        return ident;
    }
};