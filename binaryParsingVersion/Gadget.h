#ifndef GADGET_H_
#define GADGET_H_

#include <string>
#include <vector>
#include <udis86.h>
#include "FileInputOutput.h"

using namespace std;

class Operation {
public:
  Operation(const int64_t& address, const vector<uint8_t>& instractionSet, const string& asmblyInstraction);
  void Print();
  void PrintOnFile(FILE* outputFile);
private:
  friend ostream& operator<<(ostream& output, const Operation& gadget);
  int64_t _address;
  vector<uint8_t> _instractionSet;
  string _asmblyInstraction;
};


class Gadget {
public:
  Gadget(const Operation& startOperation, const Operation& endOperation, const vector<Operation>& operations, const string& fileName);
  void Print();
  void PrintOnFile(const FileInfo& input);
  static vector<Gadget> ReadGadgetsFromBinary(const FileInfo& input);
private:
  friend ostream& operator<<(ostream& output, const Gadget& gadget);
  static bool isStartOfGadget(ud_t* id_obj);
  static bool isEndOfGadget(ud_t* id_obj);
  static uint64_t getAddress(ud_t* ud_obj);
  static vector<uint8_t> getInstractionSet(ud_t* ud_obj);
  static string getAsmblyInstraction(ud_t* ud_obj);
  Operation _startOperation;
  Operation _endOperation;
  vector<Operation> _operations;
  string _fileName;
};

#endif  // GADGET_H_
