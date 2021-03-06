#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <udis86.h>
#include "Gadget.h"
#include "FileInputOutput.h"

int main(int argc, char* argv[]) {
  
  vector<FileInfo> inputInfos = FileInfo::GetInputFilesFromArguments(argc, argv);
  FileInfo outputInfo = FileInfo::GetOutputFileFromArguments(argc, argv);

  vector<Gadget> gadgets, gadgets2;
  for(unsigned i=0;i<inputInfos.size();++i) {

    gadgets = Gadget::FirstPassGadgetsRead(inputInfos[i]);
    fprintf(outputInfo.file, "First Pass\n");
    for(unsigned j=0;j<gadgets.size();++j) {
      gadgets[j].PrintOnFile(&outputInfo);
    }

    gadgets2 = Gadget::SecondPassGadgetsRead(inputInfos[i]);
    fprintf(outputInfo.file, "Second Pass\n");
    for(unsigned j=0;j<gadgets2.size();++j) {
      gadgets[j].PrintOnFile(&outputInfo);
    }

    fclose(inputInfos[i].file);
  }

  //theGadgets has all gadgets that call a register that only do a single add or subtract on the register.
  int operationsMaxLength = 5;
  vector<Gadget> theGadgets = Gadget::GetCallEndGadgetsWithSingleAddOrSub(gadgets, operationsMaxLength);
  fprintf(outputInfo.file, "Call end gadgets with single add or sub\n");
  for(unsigned i=0;i<theGadgets.size();++i) {
    theGadgets[i].PrintOnFile(&outputInfo);
  }

  fclose(outputInfo.file);
 /*
  vector<Gadget> retGadgets = Gadget::GetGadgetsEndWith("ret", gadgets);
  while(true) {
    cout << "Which ROP turing complete case would you like to test for?" << endl;
    string input;
    cin >> input;

    if(input == "add") {
     // Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "sub") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "mul") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "div") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "exit") {
      break;
    }
    else {
      cout << "Incorrect input" << endl;
    }
  }

  vector<Gadget> jmpGadgets = Gadget::GetGadgetsEndWith("jmp", gadgets);
  while(true) {
    cout << "Which JMP turing complete case would you like to test for?" << endl;
    string input;
    cin >> input;

    if(input == "add") {
     // Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "sub") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "mul") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "div") {
      //Gadget::GenerateAddProofs(retGadgets);
    }
    else if(input == "exit") {
      break;
    }
    else {
      cout << "Incorrect input" << endl;
    }
  }

*/
}
