#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Gadget.h"
#include "Sorting.h"


using namespace std;


void Branching(vector<Gadget> RetGadgets){
	//this never got any results

	vector<vector<Gadget>> branchGadgets64;
	vector<vector<Gadget>> branchGadgets32;


	for (int i = 0; i < 16; i++){


		//getting the addition gadgets and removing the side effects for 64 bit

		branchGadgets64.push_back(GetCmpGadgets(RetGadgets, _64Registers[i]));

		//getting the addition gadgets and removing the side effects for 32 bit
		branchGadgets32.push_back(GetCmpGadgets(RetGadgets, _32Registers[i]));

	}

	//print results
	//printFinalResults(loadGadgets64, subGadgets64, storageGadgets64, "_64BitSub.txt", "Sub", true);
	//printFinalResults(loadGadgets32, subGadgets32, storageGadgets32, "_32BitSub.txt", "Sub", false);
}

void Subtraction(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> subGadgets64;	
	vector<vector<Gadget>> subGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the load gadgets for 64 bit
		//loadGadgets64.push_back(LoadOperations(RetGadgets, _64Registers[i]));
		//getting the load gadgets for 32 bit
		//loadGadgets32.push_back(LoadOperations(RetGadgets, _32Registers[i]));

		//getting the addition gadgets and removing the side effects for 64 bit

		subGadgets64.push_back(RemoveMovSideEffect(GetSubGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "add"));

		//getting the addition gadgets and removing the side effects for 32 bit
		subGadgets32.push_back(RemoveMovSideEffect(GetSubGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "add"));


		//getting the storage gadgets for 64 bit
		//storageGadgets64.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _64Registers[i], _32Registers//[i]), _64Registers[i], _32Registers[i], "add"));

		//getting the storage gadgets for 32 bit
		//storageGadgets32.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _32Registers[i], _64Registers//[i]), _32Registers[i], _64Registers[i], "add"));

	}

	//print results
	printFinalResults(loadGadgets64, subGadgets64, storageGadgets64, "_64BitSub.txt","Sub",true);
	printFinalResults(loadGadgets32, subGadgets32, storageGadgets32, "_32BitSub.txt","Sub",false);

}

void Addition(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> subGadgets64;
	vector<vector<Gadget>> subGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the load gadgets for 64 bit
		loadGadgets64.push_back(LoadOperations(RetGadgets, _64Registers[i]));
		//getting the load gadgets for 32 bit
		loadGadgets32.push_back(LoadOperations(RetGadgets, _32Registers[i]));

		//getting the addition gadgets and removing the side effects for 64 bit
		subGadgets64.push_back(RemoveMovSideEffect(GetAddGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the addition gadgets and removing the side effects for 32 bit
		subGadgets32.push_back(RemoveMovSideEffect(GetAddGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));


		//getting the storage gadgets for 64 bit
		storageGadgets64.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the storage gadgets for 32 bit
		storageGadgets32.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));

	}

	//print results
	printFinalResults(loadGadgets64, subGadgets64, storageGadgets64, "_64BitAdd.txt", "Add", true);
	printFinalResults(loadGadgets32, subGadgets32, storageGadgets32, "_32BitAdd.txt", "Add", false);

}
void Multiply(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> subGadgets64;
	vector<vector<Gadget>> subGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the load gadgets for 64 bit
		loadGadgets64.push_back(LoadOperations(RetGadgets, _64Registers[i]));
		//getting the load gadgets for 32 bit
		loadGadgets32.push_back(LoadOperations(RetGadgets, _32Registers[i]));

		//getting the multiply gadgets and removing the side effects for 64 bit
		subGadgets64.push_back(RemoveMovSideEffect(GetMulGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the multiply gadgets and removing the side effects for 32 bit
		subGadgets32.push_back(RemoveMovSideEffect(GetMulGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));


		//getting the storage gadgets for 64 bit
		storageGadgets64.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the storage gadgets for 32 bit
		storageGadgets32.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));

	}

	//print results
	printFinalResults(loadGadgets64, subGadgets64, storageGadgets64, "_64BitMultiply.txt", "Multiply", true);
	printFinalResults(loadGadgets32, subGadgets32, storageGadgets32, "_32BitMultiply.txt", "Multiply", false);

}
void Divide(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> subGadgets64;
	vector<vector<Gadget>> subGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the divide gadgets and removing the side effects for 64 bit
		subGadgets64.push_back(RemoveMovSideEffect(GetDivGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the divide gadgets and removing the side effects for 32 bit
		subGadgets32.push_back(RemoveMovSideEffect(GetDivGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));


	}

	//print results
	printFinalResults(loadGadgets64, subGadgets64, storageGadgets64, "_64BitDivide.txt", "Divide", true);
	printFinalResults(loadGadgets32, subGadgets32, storageGadgets32, "_32BitDivide.txt", "Divide", false);

}
void neg(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> negGadgets64;
	vector<vector<Gadget>> negGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the divide gadgets and removing the side effects for 64 bit
		negGadgets64.push_back(RemoveMovSideEffect(GetNegGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the divide gadgets and removing the side effects for 32 bit
		negGadgets32.push_back(RemoveMovSideEffect(GetNegGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));

	}

	//print results
	printFinalResults(loadGadgets64, negGadgets64, storageGadgets64, "_64BitNeg.txt", "Neg", true);
	printFinalResults(loadGadgets32, negGadgets32, storageGadgets32, "_32BitNeg.txt", "Neg", false);

}

void ExclusiveOr(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> xorGadgets64;
	vector<vector<Gadget>> xorGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	//all the functions used in this loop can be found in 'sorting.cpp'
	for (int i = 0; i < 16; i++){

		//getting the load gadgets for 64 bit
		//loadGadgets64.push_back(LoadOperations(RetGadgets, _64Registers[i]));
		//getting the load gadgets for 32 bit
		//loadGadgets32.push_back(LoadOperations(RetGadgets, _32Registers[i]));

		//getting the divide gadgets and removing the side effects for 64 bit
		xorGadgets64.push_back(RemoveMovSideEffect(GetXorGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the divide gadgets and removing the side effects for 32 bit
		xorGadgets32.push_back(RemoveMovSideEffect(GetXorGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));


		//getting the storage gadgets for 64 bit
		//storageGadgets64.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		//getting the storage gadgets for 32 bit
		//storageGadgets32.push_back(RemoveMovSideEffectStorage(GetStorageGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));

	}

	//print results
	printFinalResults(loadGadgets64, xorGadgets64, storageGadgets64, "_64BitXor.txt", "Or", true);
	printFinalResults(loadGadgets32, xorGadgets32, storageGadgets32, "_32BitXor.txt", "Or", false);

}
void andGad(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> AndGadgets64;
	vector<vector<Gadget>> AndGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		AndGadgets64.push_back(RemoveMovSideEffect(GetAndGadgets(RetGadgets, _64Registers[i], _32Registers[i]), _64Registers[i], _32Registers[i], "sub"));

		AndGadgets32.push_back(RemoveMovSideEffect(GetAndGadgets(RetGadgets, _32Registers[i], _64Registers[i]), _32Registers[i], _64Registers[i], "sub"));


	}

	printFinalResults(loadGadgets64, AndGadgets64, storageGadgets64, "_64BitAnd.txt", "And", true);
	printFinalResults(loadGadgets32, AndGadgets32, storageGadgets32, "_32BitAnd.txt", "And", false);

}
void orGad(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> orGadgets64;
	vector<vector<Gadget>> orGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		orGadgets64.push_back(GetOrGadgets(RetGadgets, _64Registers[i], _32Registers[i]));

		orGadgets32.push_back(GetOrGadgets(RetGadgets, _32Registers[i], _64Registers[i]));


	}

	//print results
	printFinalResults(loadGadgets64, orGadgets64, storageGadgets64, "_64BitOr.txt", "Or", true);
	printFinalResults(loadGadgets32, orGadgets32, storageGadgets32, "_32BitOr.txt", "Or", false);

}


void orGad8bit(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> orGadgets64;
	vector<vector<Gadget>> orGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		orGadgets64.push_back(GetOrGadgets(RetGadgets, _8Registers[i], _32Registers[i]));
		
	}

	//print results
	printFinalResults(loadGadgets64, orGadgets64, storageGadgets64, "_8BitOr.txt", "8 Bit Or", true);

}
void andGad8bit(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> orGadgets64;
	vector<vector<Gadget>> orGadgets32;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		orGadgets64.push_back(GetAndGadgets(RetGadgets, _8Registers[i], _32Registers[i]));

	}

	//print results
	printFinalResults(loadGadgets64, orGadgets64, storageGadgets64, "_8BitAnd.txt", "8 Bit And", true);
}

void ShiftGad(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> orGadgets64;
	vector<vector<Gadget>> orGadgets32; 
	vector<vector<Gadget>> orGadgets322;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		orGadgets64.push_back(GetShiftGadgets(RetGadgets, _8Registers[i], _32Registers[i]));

		orGadgets32.push_back(GetShiftGadgets(RetGadgets, _32Registers[i], _32Registers[i]));

		orGadgets322.push_back(GetShiftGadgets(RetGadgets, _64Registers[i], _32Registers[i]));

	}

	//print results
	printFinalResults(loadGadgets64, orGadgets64, storageGadgets64, "_8BitShift.txt", "8 Bit Shift", true);
	printFinalResults(loadGadgets64, orGadgets32, storageGadgets64, "_32BitShift.txt", "shift", false);
	printFinalResults(loadGadgets64, orGadgets322, storageGadgets64, "_64BitShift.txt", "shift", true);

}
void RotateGad(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> orGadgets64;
	vector<vector<Gadget>> orGadgets32;

	vector<vector<Gadget>> orGadgets322;

	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		orGadgets64.push_back(GetRotateGadgets(RetGadgets, _8Registers[i], _32Registers[i]));

		orGadgets32.push_back(GetShiftGadgets(RetGadgets, _32Registers[i], _32Registers[i]));

		orGadgets322.push_back(GetShiftGadgets(RetGadgets, _64Registers[i], _32Registers[i]));

	}

	//print results
	printFinalResults(loadGadgets64, orGadgets64, storageGadgets64, "_8BitRotate.txt", "8 Bit Rotate", true);
	printFinalResults(loadGadgets64, orGadgets32, storageGadgets64, "_32BitRotate.txt", "Rotate", false);
	printFinalResults(loadGadgets64, orGadgets322, storageGadgets64, "_64BitRotate.txt", "Rotate", true);
}



void notGad(vector<Gadget> RetGadgets){

	vector<vector<Gadget>> loadGadgets64;
	vector<vector<Gadget>> loadGadgets32;

	vector<vector<Gadget>> notGadgets64;
	vector<vector<Gadget>> notGadgets32;
	vector<vector<Gadget>> orGadgets322;


	vector<vector<Gadget>> storageGadgets32;
	vector<vector<Gadget>> storageGadgets64;

	for (int i = 0; i < 16; i++){

		notGadgets64.push_back((GetNotGadgets(RetGadgets, _64Registers[i], _32Registers[i])));

		//getting the divide gadgets and removing the side effects for 32 bit
		notGadgets32.push_back((GetNotGadgets(RetGadgets, _32Registers[i], _64Registers[i])));


	}

	//print results
	printFinalResults(loadGadgets64, notGadgets64, storageGadgets64, "_64BitNot.txt", "Not", true);
	printFinalResults(loadGadgets32, notGadgets32, storageGadgets32, "_32BitNot.txt", "Not", false);

}



int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Wrong!!" << endl;
		exit(1);
	}

	ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		cout << argv[1] << " cannot be opened." << endl;
		exit(1);
	}

	vector<Gadget> gadgets;
	string line;
	while (getline(inputFile, line)) {
		if (!Gadget::isStartOfGadget(line)) continue;

		string start(line);
		vector<Operation> operations;
		while (getline(inputFile, line)) {
			if (Gadget::isEndOfGadget(line)) break;

			operations.push_back(Operation(line));
		}
		Gadget g (start, line, operations);

		gadgets.push_back(g);
	}	


	vector<Gadget> SysCallGads = GetSySCallGadgets(gadgets);
	PrintGadgets(SysCallGads, "SyscallLT5.txt");



	vector<Gadget> allGadgets;
	vector<Gadget> RetGadgets = GetRetGadgets(gadgets);
	vector<Gadget> JmpGadgets = GetJmpGadgets(gadgets);
	vector<Gadget> CalllGadgets = GetCallGadgets(gadgets);


	for (int i = 0; i < JmpGadgets.size(); i++){
		allGadgets.push_back(JmpGadgets[i]);
	}
	for (int i = 0; i < CalllGadgets.size(); i++){
		allGadgets.push_back(CalllGadgets[i]);
	}



	//note: these are set up to run the queries on ret gadgets, change the input to call/jmp/allGadgets to get their outputs

	RotateGad(RetGadgets);
	ShiftGad(RetGadgets);

	orGad(RetGadgets);
	andGad(RetGadgets);
	notGad(RetGadgets);

	ExclusiveOr(RetGadgets);
	Addition(RetGadgets);
	Subtraction(RetGadgets);
	Multiply(RetGadgets);
	Divide(RetGadgets);
	neg(RetGadgets);
	
	inputFile.close();
}