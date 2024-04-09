#pragma once
#include "koopa.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>

#define T0 0
#define T1 1
#define T2 2
#define T3 3
#define T4 4
#define T5 5
#define T6 6
#define A0 7
#define A1 8
#define A2 9
#define A3 10
#define A4 11
#define A5 12
#define A6 13
#define A7 14
#define X0 15

#define state0 0
#define state1 1
#define state2 2

class Reg {
public:
  int reg_idx;
  int reg_offset;

  Reg(){
    reg_idx=-1;
    reg_offset=-1;
  }

  Reg(int idx,int offset){
    reg_idx=idx;
    reg_offset=offset;
  }
};
std::string register_name[16] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6","a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "x0"};
int register_state[16] = {0};//寄存器的状态 0代表该寄存器的值不重要可被替换 1代表这个值要先保存回栈要用再加载回来 2代表不能被替换
koopa_raw_value_t register_value[16];//寄存器对应的value
koopa_raw_value_t present_value = 0;
std::map<const koopa_raw_value_t, Reg> value_reg_map;
int stack_size = 0, stack_top = 0;
bool restore_ra = false;

void Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_slice_t &slice);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_return_t &ret);
Reg Visit(const koopa_raw_value_t &value);
Reg Visit(const koopa_raw_integer_t &integer);
Reg Visit(const koopa_raw_binary_t &binary);
Reg Visit(const koopa_raw_load_t &load);
void Visit(const koopa_raw_store_t &store);
void Visit(const koopa_raw_branch_t &branch);
void Visit(const koopa_raw_jump_t &jump);


static inline void print_instr(const char* op,int reg_idx1,int reg_idx2,int reg_idx3)//打印指令
{
  std::cout<<"\t"<<op<<" "<<register_name[reg_idx1]<<", "<<register_name[reg_idx2]<<", "<<register_name[reg_idx3]<<std::endl;
}

int find_available_register(int state){
  for (int i = 0; i < 15; i++)
    if (register_state[i] == 0){//0代表该寄存器的值不重要可被替换 则用它来存
      register_value[i] = present_value;
      register_state[i] = state;
      return i;
    }
  for (int i = 0; i < 15; i++){
    if (register_state[i] == 1){// 1代表这个值要先保存回栈要用再加载回来
      value_reg_map[register_value[i]].reg_idx = -1;
      int offset = value_reg_map[register_value[i]].reg_offset;
      if (offset == -1){
          offset = stack_top;
          stack_top += 4;
          value_reg_map[register_value[i]].reg_offset = offset;
      }
      if (offset >= -2048 && offset <= 2047)
          std::cout << "\tsw    " << register_name[i] << ", " << offset << "(sp)" << std::endl;
      else{
          std::cout << "\tli    s11, " << offset << std::endl;
          std::cout << "\tadd   s11, s11, sp" << std::endl;
          std::cout << "\tsw    " << register_name[i] << ", (s11)" << std::endl;
      }
      register_value[i] = present_value;
      register_state[i] = state;
      return i;
    }
  }
  assert(false);
  return -1;
}


// 访问 raw program
void Visit(const koopa_raw_program_t &program) {
  // 执行一些其他的必要操作
  // 访问所有全局变量
  Visit(program.values);
  // 访问所有函数
  Visit(program.funcs);
}

// 访问 raw slice
void Visit(const koopa_raw_slice_t &slice)
{
  for (size_t i = 0; i < slice.len; i++){
    auto ptr = slice.buffer[i];
    // 根据 slice 的 kind 决定将 ptr 视作何种元素
    switch (slice.kind){
    case KOOPA_RSIK_FUNCTION:
      // 访问函数
      Visit(reinterpret_cast<koopa_raw_function_t>(ptr));
      break;
    case KOOPA_RSIK_BASIC_BLOCK:
      // 访问基本块
      Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
      break;
    case KOOPA_RSIK_VALUE:
      // 访问指令
      Visit(reinterpret_cast<koopa_raw_value_t>(ptr));
      break;
    default:
      // 我们暂时不会遇到其他内容, 于是不对其做任何处理
      assert(false);
    }
  }
}


// 访问函数
void Visit(const koopa_raw_function_t &func)
{
  if (func->bbs.len == 0){
    return;
  }
  std::cout << "\t.text" << std::endl;
  std::cout << "\t.globl " << (func->name + 1) << std::endl;
  std::cout << (func->name + 1) << ":" << std::endl;
  int max_arg_num = 0;
  // 访问所有基本块
  for (size_t i = 0; i < func->bbs.len; ++i)
  {
    auto ptr = func->bbs.buffer[i];
    koopa_raw_basic_block_t bb = reinterpret_cast<koopa_raw_basic_block_t>(ptr);
    for (size_t j = 0; j < bb->insts.len; ++j)
    {
      ptr = bb->insts.buffer[j];
      koopa_raw_value_t inst = reinterpret_cast<koopa_raw_value_t>(ptr);
      if (inst->ty->tag != KOOPA_RTT_UNIT)
      {
        if (inst->kind.tag == KOOPA_RVT_ALLOC)
            stack_size += 4;
        else stack_size += 4;
      }
    }
  }
  int arg_stack_size = 0;
  if (max_arg_num > 8)arg_stack_size = (max_arg_num - 8) * 4;
  stack_size += arg_stack_size;
  stack_top += arg_stack_size;
  if (restore_ra)stack_size += 4;
  stack_size = ceil(stack_size / 16.0) * 16;
  if (stack_size > 0 && stack_size <= 2048)
    std::cout << "\taddi  sp, sp, -" << stack_size << std::endl;
  else if (stack_size > 2048)
  {
    std::cout << "\tli    s11, -" << stack_size << std::endl;
    std::cout << "\tadd   sp, sp, s11" << std::endl;
  }
  if (restore_ra)
  {
    if (stack_size - 4 >= -2048 && stack_size - 4 <= 2047)
      std::cout << "\tsw    ra, " << stack_size - 4 << "(sp)" << std::endl;
    else
    {
      std::cout << "\tli    s11, " << stack_size - 4 << std::endl;
      std::cout << "\tadd   s11, sp, s11" << std::endl;
      std::cout << "\tsw    ra, (s11)" << std::endl;
    }
  }
  for (size_t i = 0; i < func->params.len; ++i){
    auto ptr = func->params.buffer[i];
    koopa_raw_value_t param = reinterpret_cast<koopa_raw_value_t>(ptr);
    if (i < 8)
    {
      Reg param_var = Reg(static_cast<int>(i + 7), -1);
      value_reg_map[param] = param_var;
    }
    else
    {
      int offset = stack_size + (i - 8) * 4;
      Reg param_var = Reg(-1, offset);
      value_reg_map[param] = param_var;
    }
  }
  Visit(func->bbs);
  stack_size = stack_top = 0;
  for (int i = 0; i < 16; ++i){
    register_state[i] = 0;
  }
  value_reg_map.clear();
  restore_ra = false;
  std::cout << std::endl;
}

// 访问基本块
void Visit(const koopa_raw_basic_block_t &bb)
{
  std::cout << bb->name + 1 << ":" << std::endl;
  // 访问所有指令
  Visit(bb->insts);
}

// 访问指令
Reg Visit(const koopa_raw_value_t &value)
{
  //如果所求值已经存在则不需要再次求值 就直接加载
  koopa_raw_value_t old_value = present_value;
  present_value = value;
  if (value_reg_map.count(value)){
    if (value_reg_map[value].reg_idx == -1){
      int reg_idx = find_available_register(state1);
      value_reg_map[value].reg_idx = reg_idx;
      int reg_offset = value_reg_map[value].reg_offset;
      if (reg_offset >= -2048 && reg_offset <= 2047){
        std::cout << "\tlw    " << register_name[reg_idx] << ", " << reg_offset << "(sp)" << std::endl;
      }
      else{
        std::cout << "\tli    s11, " << reg_offset << std::endl;
        std::cout << "\tadd   s11, sp, s11" << std::endl;
        std::cout << "\tlw    " << register_name[reg_idx] << ", (s11)" << std::endl;
      }
    }
    present_value = old_value;
    return value_reg_map[value];
  }

  const auto &kind = value->kind;
  Reg res_reg = Reg(-1, -1);
  switch (kind.tag){
  case KOOPA_RVT_RETURN:
    Visit(kind.data.ret);
    break;
  case KOOPA_RVT_INTEGER:
    res_reg = Visit(kind.data.integer);
    break;
  case KOOPA_RVT_BINARY:
    res_reg = Visit(kind.data.binary);
    value_reg_map[value] = res_reg;
    break;
  case KOOPA_RVT_ALLOC:
    res_reg.reg_offset = stack_top;
    stack_top += 4;
    value_reg_map[value] = res_reg;
    break;
  case KOOPA_RVT_LOAD:
    res_reg = Visit(kind.data.load);
    value_reg_map[value] = res_reg;
    break;
  case KOOPA_RVT_STORE:
    Visit(kind.data.store);
    break;
  case KOOPA_RVT_BRANCH:
    Visit(kind.data.branch);
    break;
  case KOOPA_RVT_JUMP:
    Visit(kind.data.jump);
    break;
  default:
    assert(false);
  }
  present_value = old_value;
  return res_reg;
}

// 访问return指令
void Visit(const koopa_raw_return_t &ret)
{
  koopa_raw_value_t ret_value = ret.value;
  if (ret_value){
    Reg res_reg = Visit(ret_value);
    assert(res_reg.reg_idx >= 0);
    if (res_reg.reg_idx != 7)
        std::cout << "\tmv    a0, " << register_name[res_reg.reg_idx] << std::endl;
  }
  if (restore_ra){
    if (stack_size - 4 >= -2048 && stack_size - 4 <= 2047){
      std::cout << "\tlw    ra, " << stack_size - 4 << "(sp)" << std::endl;
    }
    else{
      std::cout << "\tli    t0, " << stack_size - 4 << std::endl;
      std::cout << "\tadd   t0, sp, t0" << std::endl;
      std::cout << "\tlw    ra, (t0)" << std::endl;
    }
  }
  if (stack_size > 0 && stack_size <= 2047){
    std::cout << "\taddi  sp, sp, " << stack_size << std::endl;
  }
  else if (stack_size > 2047){
    std::cout << "\tli    t0, " << stack_size << std::endl;
    std::cout << "\tadd   sp, sp, t0" << std::endl;
  }
  std::cout << "\tret" << std::endl;
}

//访问integer指令
Reg Visit(const koopa_raw_integer_t &integer)
{
  int32_t int_val = integer.value;
  Reg res_reg = Reg(-1, -1);
  if (int_val == 0) {
    res_reg.reg_idx = X0;
    return res_reg;
  }
  res_reg.reg_idx = find_available_register(state0);
  std::cout << "\tli    " << register_name[res_reg.reg_idx] << ", " << int_val << std::endl;
  return res_reg;
}


Reg Visit(const koopa_raw_binary_t &binary)
{
  Reg left_val = Visit(binary.lhs); //binary.lhs是koopa_raw_value_t
  int left_reg = left_val.reg_idx;
  int tmp = register_state[left_reg];
  register_state[left_reg] = state2;//标记为不可更换 过会儿换回来

  Reg right_val = Visit(binary.rhs);
  int right_reg = right_val.reg_idx;
  register_state[left_reg] = tmp;
  tmp = register_state[right_reg];
  register_state[right_reg] = state2;

  Reg res_reg = Reg(find_available_register(state1), -1);
  register_state[right_reg] = tmp;
  int res_reg_idx = res_reg.reg_idx;

  switch (binary.op){
  case KOOPA_RBO_NOT_EQ:
    if (register_name[left_reg] == "x0"){
      std::cout << "\tsnez  " << register_name[res_reg_idx] << ", " << register_name[right_reg] << std::endl;
      break;
    }
    if (register_name[right_reg] == "x0"){
      std::cout << "\tsnez  " << register_name[res_reg_idx] << ", " << register_name[left_reg] << std::endl;
      break;
    }
    print_instr("xor",res_reg_idx,left_reg,right_reg);
    std::cout << "\tsnez  " << register_name[res_reg_idx] << ", " << register_name[res_reg_idx] << std::endl;
    break;
  case KOOPA_RBO_EQ:
    if (register_name[left_reg] == "x0"){
      std::cout << "\tseqz  " << register_name[res_reg_idx] << ", " << register_name[right_reg] << std::endl;
      break;
    }
    if (register_name[right_reg] == "x0"){
      std::cout << "\tseqz  " << register_name[res_reg_idx] << ", " << register_name[left_reg] << std::endl;
      break;
    }
    print_instr("xor",res_reg_idx,left_reg,right_reg);
    std::cout << "\tseqz  " << register_name[res_reg_idx] << ", " << register_name[res_reg_idx] << std::endl;
    break;
  case KOOPA_RBO_GT:
    print_instr("sgt",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_LT:
    print_instr("slt",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_GE:
    print_instr("slt",res_reg_idx,left_reg,right_reg);
    std::cout << "\txori  " << register_name[res_reg_idx] << ", " << register_name[res_reg_idx] << ", 1" << std::endl;
    break;
  case KOOPA_RBO_LE:
    print_instr("sgt",res_reg_idx,left_reg,right_reg);
    std::cout << "\txori  " << register_name[res_reg_idx] << ", " << register_name[res_reg_idx] << ", 1" << std::endl;
    break;
  case KOOPA_RBO_ADD:
    print_instr("add",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_SUB:
    print_instr("sub",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_MUL:
    print_instr("mul",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_DIV:
    print_instr("div",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_MOD:
    print_instr("rem",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_AND:
    print_instr("and",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_OR:
    print_instr("or",res_reg_idx,left_reg,right_reg);
    break;
  case KOOPA_RBO_XOR:
    break;
  case KOOPA_RBO_SHL:
    break;
  case KOOPA_RBO_SHR:
    break;
  case KOOPA_RBO_SAR:
    break;
  default:
    std::cout<<"Error:visit(const koopa_raw_binary_t &binary)\n";
    assert(false);
  }
  return res_reg;
}


Reg Visit(const koopa_raw_load_t &load)
{
  koopa_raw_value_t src = load.src;
  if (value_reg_map[src].reg_idx >= 0){
    return value_reg_map[src];
  }
  int reg_idx = find_available_register(state1);
  int reg_offset = value_reg_map[src].reg_offset;
  Reg res_reg = Reg(reg_idx, reg_offset);
  if (reg_offset >= -2048 && reg_offset <= 2047)
    std::cout << "\tlw    " << register_name[reg_idx] << ", " << reg_offset << "(sp)" << std::endl;
  else{
    std::cout << "\tli    s11, " << reg_offset << std::endl;
    std::cout << "\tadd   s11, s11, sp" << std::endl;
    std::cout << "\tlw    " << register_name[reg_idx] << ", (s11)" << std::endl;
  }
  return res_reg;
}


void Visit(const koopa_raw_store_t &store)
{
  Reg value = Visit(store.value);
  koopa_raw_value_t dest = store.dest;
  if (value_reg_map[dest].reg_offset == -1){
    value_reg_map[dest].reg_offset = stack_top;
    stack_top += 4;
  }
  else{
    for (int i = 0; i < 16; i++){
      if (i == value.reg_idx){
        continue;
      }
      else if (register_state[i] > 0 && value_reg_map[register_value[i]].reg_offset == value_reg_map[dest].reg_offset){
        register_state[i] = state0;
        value_reg_map[register_value[i]].reg_idx = value.reg_idx;
      }
    }
  }
  int reg_idx = value.reg_idx;
  int reg_offset = value_reg_map[dest].reg_offset;
  if (reg_offset >= -2048 && reg_offset <= 2047)
    std::cout << "\tsw    " << register_name[reg_idx] << ", " << reg_offset << "(sp)" << std::endl;
  else
  {
    std::cout << "\tli    s11, " << reg_offset << std::endl;
    std::cout << "\tadd   s11, s11, sp" << std::endl;
    std::cout << "\tsw    " << register_name[reg_idx] << ", (s11)" << std::endl;
  }
}


void Visit(const koopa_raw_branch_t &branch)
{
  int cond_reg_idx = Visit(branch.cond).reg_idx;
  std::cout << "\tbnez  " << register_name[cond_reg_idx] << ", " << (branch.true_bb->name + 1) << std::endl;
  std::cout << "\tj     " << (branch.false_bb->name + 1) << std::endl;
}


void Visit(const koopa_raw_jump_t &jump)
{
  std::cout << "\tj     " << (jump.target->name + 1) << std::endl;
}
