#ifndef SORTING_H_ 
#define SORTING_H_

#include <string>
#include <vector>
#include "Gadget.h"

using namespace std;

vector<Gadget> GetRetGadgets(vector<Gadget> gadgets); 
vector<Gadget> GetSySCallGadgets(vector<Gadget> gadgets);


vector<Gadget> GetCmpGadgets(vector<Gadget> gadgets, string sup);

vector<Gadget> GetJmpGadgets(vector<Gadget> gadgets);
vector<Gadget> GetCallGadgets(vector<Gadget> gadgets);


vector<Gadget> LoadOperations(vector<Gadget> gadgets, string reg);


vector<Gadget> RemoveMovSideEffect(vector<Gadget> gadgets, string _64reg, string _32reg, string addOrSub);
vector<Gadget> RemoveMovSideEffectStorage(vector<Gadget> gadgets, string _64reg, string _32reg, string addOrSub);


vector<Gadget> GetAddGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetSubGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetDivGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetMulGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetNegGadgets(vector<Gadget> gadgets, string reg1, string reg2);

vector<Gadget> GetXorGadgets(vector<Gadget> gadgets, string reg1, string reg2);

vector<Gadget> GetOrGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetAndGadgets(vector<Gadget> gadgets, string reg1, string reg2); 
vector<Gadget> GetNotGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetRotateGadgets(vector<Gadget> gadgets, string reg1, string reg2);
vector<Gadget> GetShiftGadgets(vector<Gadget> gadgets, string reg1, string reg2);

vector<Gadget> GetStorageGadgets(vector<Gadget> gadgets, string _64reg, string _32reg);

vector<string> splitstuff(string line);

void PrintGadgets(vector<Gadget> gadgets, string filename);
void PrintGadgetss(vector<Gadget> gadgets, int numd, string filename, string typed);
void printFinalResults(vector<vector<Gadget>> load, vector<vector<Gadget>> add, vector<vector<Gadget>> store, string fileName, string typeOfOp, bool is64);

bool isRegister(string reg);

#endif  // SORTING_H_ 