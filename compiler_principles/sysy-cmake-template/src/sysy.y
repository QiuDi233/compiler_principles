%code requires {
  #include <memory>
  #include <string>
  #include "AST.h"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include "AST.h"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;

%}


%parse-param { std::unique_ptr<BaseAST> &ast }

%union {
  std::string *str_val;
  int int_val;
  BaseAST *ast_val;
  std::vector<std::unique_ptr<BaseAST>> *vec_val;
}

%token INT VOID RETURN CONST
%token <str_val> IDENT
%token <int_val> INT_CONST
%token <str_val> OR AND EQ NE LE GE
%token <str_val> IF ELSE WHILE BREAK CONTINUE

// 非终结符的类型定义
%type <ast_val> FuncDef FuncType Block BlockItem Stmt EndStmt NotEndStmt
%type <ast_val> Exp UnaryExp PrimaryExp AddExp MulExp RelExp EqExp LAndExp LOrExp
%type <ast_val> Decl ConstDecl ConstDef ConstInitVal LVal ConstExp
%type <ast_val> VarDecl VarDef InitVal
%type <vec_val> ConstDefList BlockItemList VarDefList FuncFParams FuncRParams
%type <vec_val> ConstExpList ConstInitValList InitValList ExpList
%type <ast_val> FuncFParam CompUnitList
%type <int_val> Number
%type <str_val> UNARYOP ADDOP MULOP RELOP EQOP LANDOP LOROP
%type <str_val> BType

%%

CompUnit
  : CompUnitList {
    auto comp_unit = unique_ptr<BaseAST>($1);
    ast = move(comp_unit);
  }
  ;

CompUnitList
  : FuncDef {
    auto comp_unit = new CompUnitAST();
    auto func_def = unique_ptr<BaseAST>($1);
    comp_unit->func_def_list.push_back(move(func_def));
    $$ = comp_unit;
  }
  | CompUnitList FuncDef {
    auto comp_unit = (CompUnitAST*)($1);
    auto func_def = unique_ptr<BaseAST>($2);
    comp_unit->func_def_list.push_back(move(func_def));
    $$ = comp_unit;
  }
  | Decl {
    auto comp_unit = new CompUnitAST();
    auto decl = unique_ptr<BaseAST>($1);
    comp_unit->decl_list.push_back(move(decl));
    $$ = comp_unit;
  }
  | CompUnitList Decl {
    auto comp_unit = (CompUnitAST*)($1);
    auto decl = unique_ptr<BaseAST>($2);
    comp_unit->decl_list.push_back(move(decl));
    $$ = comp_unit;
  }
  ;

FuncDef
  : FuncType IDENT '(' ')' Block {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>($1);
    ast->ident = *unique_ptr<string>($2);
    ast->block = unique_ptr<BaseAST>($5);
    $$ = ast;
  }
  | FuncType IDENT '(' FuncFParams ')' Block {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>($1);
    ast->ident = *unique_ptr<string>($2);
    vector<unique_ptr<BaseAST>> *list = ($4);
    for (auto it = list->begin(); it != list->end(); it++)
        ast->func_f_params.push_back(move(*it));
    ast->block = unique_ptr<BaseAST>($6);
    ((BlockAST*)(ast->block).get())->func_ident = ast->ident;
    $$ = ast;
  }
  ;

// 同上, 不再解释
FuncType
  : INT {
    auto ast = new FuncTypeAST();
    ast->type = "int";
    $$ = ast;
  }
  | VOID {
    auto ast = new FuncTypeAST();
    ast->type = "void";
    $$ = ast;
  }
  ;

FuncFParams
  : FuncFParam {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>($1));
      $$ = list;
  }
  | FuncFParams ',' FuncFParam {
      vector<unique_ptr<BaseAST>> *list = ($1);
      list->push_back(unique_ptr<BaseAST>($3));
      $$ = list;
  }
  ;

FuncFParam
  : BType IDENT {
      auto ast = new FuncFParamAST();
      ast->type = FuncFParamType::var;
      ast->b_type = *unique_ptr<string>($1);
      ast->ident = *unique_ptr<string>($2);
      $$ = ast;
  }
  | BType IDENT '[' ']' {
      auto ast = new FuncFParamAST();
      ast->type = FuncFParamType::arr;
      ast->b_type = *unique_ptr<string>($1);
      ast->ident = *unique_ptr<string>($2);
      $$ = ast;
    }
  ;

Block
  : '{' BlockItemList '}' {
    auto block = new BlockAST();
    vector<unique_ptr<BaseAST>> *list = ($2);
    for (auto it = list->begin(); it != list->end(); it++)
        block->block_item_list.push_back(move(*it));
    $$ = block;
  }
  ;

BlockItemList
  : {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      $$ = list;
  }
  | BlockItemList BlockItem {
      vector<unique_ptr<BaseAST>> *list = ($1);
      list->push_back(unique_ptr<BaseAST>($2));
      $$ = list;
  }
  ;

BlockItem
  : Decl {
    auto ast = new BlockItemAST();
    ast->type = BlockItemType::decl;
    ast->decl = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  | Stmt {
    auto ast = new BlockItemAST();
    ast->type = BlockItemType::stmt;
    ast->stmt = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;

Stmt
  : EndStmt {
      auto ast = ($1);
      $$ = ast;
  }
  | NotEndStmt {
      auto ast = ($1);
      $$ = ast;
  }
  ;

EndStmt
  : LVal '=' Exp ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::lval;
    ast->lval = unique_ptr<BaseAST>($1);
    ast->exp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  | Exp ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::exp;
    ast->exp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  | ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::exp;
    ast->exp = nullptr;
    $$ = ast;
  }
  | Block {
    auto ast = new StmtAST();
    ast->type = StmtType::block;
    ast->block = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  | RETURN Exp ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::ret;
    ast->exp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  | IF '(' Exp ')' EndStmt ELSE EndStmt {
      auto ast = new StmtAST();
      ast->type = StmtType::if_else;
      ast->exp = unique_ptr<BaseAST>($3);
      ast->if_stmt = unique_ptr<BaseAST>($5);
      ast->else_stmt = unique_ptr<BaseAST>($7);
      $$ = ast;
  }
  | WHILE '(' Exp ')' EndStmt {
    auto ast = new StmtAST();
    ast->type = StmtType::while_;
    ast->exp = unique_ptr<BaseAST>($3);
    ast->while_stmt = unique_ptr<BaseAST>($5);
    $$ = ast;
  }
  | BREAK ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::break_;
    $$ = ast;
  }
  | CONTINUE ';' {
    auto ast = new StmtAST();
    ast->type = StmtType::continue_;
    $$ = ast;
  }
  ;

NotEndStmt
    : IF '(' Exp ')' Stmt {
        auto ast = new StmtAST();
        ast->type = StmtType::if_;
        ast->exp = unique_ptr<BaseAST>($3);
        ast->if_stmt = unique_ptr<BaseAST>($5);
        $$ = ast;
    }
    | IF '(' Exp ')' EndStmt ELSE NotEndStmt {
        auto ast = new StmtAST();
        ast->type = StmtType::if_else;
        ast->exp = unique_ptr<BaseAST>($3);
        ast->if_stmt = unique_ptr<BaseAST>($5);
        ast->else_stmt = unique_ptr<BaseAST>($7);
        $$ = ast;
    }
    ;

Number
  : INT_CONST {
    $$ = int($1);
  }
  ;

Decl
  : ConstDecl {
      auto exp = new DeclAST();
      exp->type = DeclType::cst;
      exp->const_decl_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | VarDecl {
      auto exp = new DeclAST();
      exp->type = DeclType::var;
      exp->var_decl_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  ;

ConstDecl
  : CONST BType ConstDefList ';' {
      auto exp = new ConstDeclAST();
      exp->b_type = *unique_ptr<string>($2);
      vector<unique_ptr<BaseAST>> *list = ($3);
      for (auto it = list->begin(); it != list->end(); it++)
          exp->const_def_list.push_back(move(*it));
      $$ = exp;
  }
  ;

ConstDefList
  : ConstDef {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>($1));
      $$ = list;
  }
  | ConstDefList ',' ConstDef {
      vector<unique_ptr<BaseAST>> *list = ($1);
      list->push_back(unique_ptr<BaseAST>($3));
      $$ = list;
  }
  ;

ConstDef
  : IDENT '=' ConstInitVal {
      auto exp = new ConstDefAST();
      exp->ident = *unique_ptr<string>($1);
      exp->const_init_val = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  | IDENT ConstExpList '=' ConstInitVal {
      auto ast = new ConstDefAST();
      ast->ident = *unique_ptr<string>($1);
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      ast->const_init_val = unique_ptr<BaseAST>($4);
      $$ = ast;
  }
  ;

ConstExpList
  : '[' ConstExp ']' {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>($2));
      $$ = ast;
  }
  | ConstExpList '[' ConstExp ']' {
      vector<unique_ptr<BaseAST>> *ast = ($1);
      ast->push_back(unique_ptr<BaseAST>($3));
      $$ = ast;
  }
  ;

ConstInitVal
  : ConstExp {
      auto exp = new ConstInitValAST();
      exp->type = ConstInitValType::const_exp;
      exp->const_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | '{' '}' {
      auto exp = new ConstInitValAST();
      exp->type = ConstInitValType::const_exp_list;
      $$ = exp;
  }
  | '{' ConstInitValList '}' {
      auto ast = new ConstInitValAST();
      ast->type = ConstInitValType::const_exp_list;
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_initval_list.push_back(move(*it));
      $$ = ast;
    }
  ;

ConstInitValList
    : ConstInitVal {
        vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
        ast->push_back(unique_ptr<BaseAST>($1));
        $$ = ast;
    }
    | ConstInitValList ',' ConstInitVal {
        vector<unique_ptr<BaseAST>> *ast = ($1);
        ast->push_back(unique_ptr<BaseAST>($3));
        $$ = ast;
    }
    ;


ConstExp
  : Exp {
      auto const_exp = new ConstExpAST();
      const_exp->exp = unique_ptr<BaseAST>($1);
      $$ = const_exp;
  }
  ;

VarDecl
  : FuncType VarDefList ';' { // 这里本来是BType的 但是不知道为什么CompUnitList 一加FuncDef就识别不了VarDecl了 改成和FuncDef一样的类型就好了
      auto exp = new VarDeclAST();
      // exp->b_type = *unique_ptr<string>($1);
      exp->b_type = "int";
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          exp->var_def_list.push_back(move(*it));
      $$ = exp;
  }
  ;

VarDefList
  : VarDef {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>($1));
      $$ = list;
  }
  | VarDefList ',' VarDef {
      vector<unique_ptr<BaseAST>> *list = ($1);
      list->push_back(unique_ptr<BaseAST>($3));
      $$ = list;
  }
  ;

VarDef
  : IDENT {
      auto exp = new VarDefAST();
      exp->type = VarDefType::ident;
      exp->ident = *unique_ptr<string>($1);
      $$ = exp;
  }
  | IDENT '=' InitVal {
      auto exp = new VarDefAST();
      exp->type = VarDefType::ident_initval;
      exp->ident = *unique_ptr<string>($1);
      exp->init_val = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  | IDENT ConstExpList {
      auto ast = new VarDefAST();
      ast->type = VarDefType::ident;
      ast->ident = *unique_ptr<string>($1);
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      $$ = ast;
  }
  | IDENT ConstExpList '=' InitVal {
      auto ast = new VarDefAST();
      ast->type = VarDefType::ident_initval;
      ast->ident = *unique_ptr<string>($1);
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      ast->init_val = unique_ptr<BaseAST>($4);
      $$ = ast;
  }
  ;

InitVal
  : Exp {
      auto init_val = new InitValAST();
      init_val->type = InitValType::exp;
      init_val->exp = unique_ptr<BaseAST>($1);
      $$ = init_val;
  }
  | '{' '}' {
      auto ast = new InitValAST();
      ast->type = InitValType::init_val_list;
      $$ = ast;
    }
    | '{' InitValList '}' {
      auto ast = new InitValAST();
      ast->type = InitValType::init_val_list;
      vector<unique_ptr<BaseAST>> *list= ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->init_val_list.push_back(move(*it));
      $$ = ast;
    }
  ;

InitValList
    : InitVal {
        vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
        ast->push_back(unique_ptr<BaseAST>($1));
        $$ = ast;
    }
    | InitValList ',' InitVal {
        vector<unique_ptr<BaseAST>> *ast = ($1);
        ast->push_back(unique_ptr<BaseAST>($3));
        $$ = ast;
    }
    ;

Exp
  : LOrExp {
      auto exp = new ExpAST();
      exp->lor_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  ;

LOROP
  : OR {
      string *op = new string("||");
      $$ = op;
  }
  ;

LANDOP
  : AND {
      string *op = new string("&&");
      $$ = op;
  }
  ;

EQOP
  : EQ {
      string *op = new string("==");
      $$ = op;
  }
  | NE {
      string *op = new string("!=");
      $$ = op;
  }
  ;

RELOP
  : '<' {
      string *op = new string("<");
      $$ = op;
  }
  | '>' {
      string *op = new string(">");
      $$ = op;
  }
  | LE {
      string *op = new string("<=");
      $$ = op;
  }
  | GE {
      string *op = new string(">=");
      $$ = op;
  }
  ;

ADDOP
  : '+' {
      string *op = new string("+");
      $$ = op;
  }
  | '-' {
      string *op = new string("-");
      $$ = op;
  }
  ;

MULOP
  : '*' {
      string *op = new string("*");
      $$ = op;
  }
  | '/' {
      string *op = new string("/");
      $$ = op;
  }
  | '%' {
      string *op = new string("%");
      $$ = op;
  }
  ;

UNARYOP
  : '+' {
      string *op = new string("+");
      $$ = op;
  }
  | '-' {
      string *op = new string("-");
      $$ = op;
  }
  | '!' {
      string *op = new string("!");
      $$ = op;
  }
  ;

LOrExp
  : LAndExp {
      auto exp = new LOrExpAST();
      exp->type = LOrExpType::land;
      exp->land_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | LOrExp LOROP LAndExp {
      auto exp = new LOrExpAST();
      exp->type = LOrExpType::lor_land;
      exp->op = *unique_ptr<string>($2);
      exp->lor_exp = unique_ptr<BaseAST>($1);
      exp->land_exp = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  ;

LAndExp
  : EqExp {
      auto exp = new LAndExpAST();
      exp->type = LAndExpType::eq;
      exp->eq_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | LAndExp LANDOP EqExp {
      auto exp = new LAndExpAST();
      exp->type = LAndExpType::land_eq;
      exp->op = *unique_ptr<string>($2);
      exp->land_exp = unique_ptr<BaseAST>($1);
      exp->eq_exp = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  ;

EqExp
  : RelExp {
      auto exp = new EqExpAST();
      exp->type = EqExpType::rel;
      exp->rel_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | EqExp EQOP RelExp {
      auto exp = new EqExpAST();
      exp->type = EqExpType::eq_rel;
      exp->op = *unique_ptr<string>($2);
      exp->eq_exp = unique_ptr<BaseAST>($1);
      exp->rel_exp = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  ;

RelExp
  : AddExp {
      auto exp = new RelExpAST();
      exp->type = RelExpType::add;
      exp->add_exp = unique_ptr<BaseAST>($1);
      $$ = exp;
  }
  | RelExp RELOP AddExp {
      auto exp = new RelExpAST();
      exp->type = RelExpType::rel_add;
      exp->op = *unique_ptr<string>($2);
      exp->rel_exp = unique_ptr<BaseAST>($1);
      exp->add_exp = unique_ptr<BaseAST>($3);
      $$ = exp;
  }
  ;

AddExp
  : MulExp {
      auto add_exp = new AddExpAST();
      add_exp->type = AddExpType::mul;
      add_exp->mul_exp = unique_ptr<BaseAST>($1);
      $$ = add_exp;
  }
  | AddExp ADDOP MulExp {
      auto add_exp = new AddExpAST();
      add_exp->type = AddExpType::add_mul;
      add_exp->op = *unique_ptr<string>($2);
      add_exp->add_exp = unique_ptr<BaseAST>($1);
      add_exp->mul_exp = unique_ptr<BaseAST>($3);
      $$ = add_exp;
  }
  ;

MulExp
  : UnaryExp {
      auto mul_exp = new MulExpAST();
      mul_exp->type = MulExpType::unary;
      mul_exp->unary_exp = unique_ptr<BaseAST>($1);
      $$ = mul_exp;
  }
  | MulExp MULOP UnaryExp {
      auto mul_exp = new MulExpAST();
      mul_exp->type = MulExpType::mul_unary;
      mul_exp->op = *unique_ptr<string>($2);
      mul_exp->mul_exp = unique_ptr<BaseAST>($1);
      mul_exp->unary_exp = unique_ptr<BaseAST>($3);
      $$ = mul_exp;
  }
  ;

UnaryExp
  : PrimaryExp {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::primary;
      unary_exp->primary_exp = unique_ptr<BaseAST>($1);
      $$ = unary_exp;
  }
  | UNARYOP UnaryExp {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::unary;
      unary_exp->unary_op = *unique_ptr<string>($1);
      unary_exp->unary_exp = unique_ptr<BaseAST>($2);
      $$ = unary_exp;
  }
  | IDENT '('')' {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::func;
      unary_exp->ident = *unique_ptr<string>($1);
      $$ = unary_exp;
  }
  | IDENT '(' FuncRParams ')' {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::func;
      unary_exp->ident = *unique_ptr<string>($1);
      vector<unique_ptr<BaseAST>> *list = ($3);
      for (auto it = list->begin(); it != list->end(); it++)
        unary_exp->func_r_params.push_back(move(*it));
      $$ = unary_exp;
  }
  ;

FuncRParams
  : Exp {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>($1));
      $$ = ast;
  }
  | FuncRParams ',' Exp {
      vector<unique_ptr<BaseAST>> *ast = ($1);
      ast->push_back(unique_ptr<BaseAST>($3));
      $$ = ast;
  }
  ;


PrimaryExp
  : '(' Exp ')' {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::exp;
      primary_exp->exp = unique_ptr<BaseAST>($2);
      $$ = primary_exp;
  }
  | LVal {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::lval;
      primary_exp->lval = unique_ptr<BaseAST>($1);
      $$ = primary_exp;
  }
  | Number {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::number;
      primary_exp->number = ($1);
      $$ = primary_exp;
  }
  ;

LVal
  : IDENT {
      auto ast = new LValAST();
      ast->ident = *unique_ptr<string>($1);
      $$ = ast;
  }
  | IDENT ExpList {
      auto ast = new LValAST();
      ast->ident = *unique_ptr<string>($1);
      vector<unique_ptr<BaseAST>> *list = ($2);
      for (auto it = list->begin(); it != list->end(); it++)
          ast->exp_list.push_back(move(*it));
      $$ = ast;
  }
  ;

ExpList
  : '[' Exp ']' {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>($2));
      $$ = ast;
  }
  | ExpList '[' Exp ']' {
      vector<unique_ptr<BaseAST>> *ast = ($1);
      ast->push_back(unique_ptr<BaseAST>($3));
      $$ = ast;
  }
  ;

BType
  : INT {
      string *type = new string("int");
      $$ = type;
  }
    ;



%%




void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}
