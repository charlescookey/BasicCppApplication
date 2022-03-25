// BasicProgram.cpp : Defines the entry point for the application.
//

#include "BasicProgram.h"

#include "ezOptionParser.hpp"
#include <fstream>
#include <string>


using std::cout;
using std::endl;
using ez::ezOptionParser;

void showUsage(ezOptionParser& opt);
void initializeParser(ezOptionParser& opt);
bool isMissingParams(ezOptionParser& opt);
void showProgramCall(ezOptionParser& opt);

using namespace std;

int main(int argc, const char* argv[])
{
    ezOptionParser opt;
    initializeParser(opt);
    opt.parse(argc, argv);
    if (opt.isSet("-h") || isMissingParams(opt))
    {
        showUsage(opt);
        return 0;
    }
    int a

    showProgramCall(opt);

    std::string filename;
    opt.get("-i")->getString(filename);
    ifstream input(filename);

    ofstream myfile;
    bool output = false;
    if (opt.isSet("-o")) {
        output = true;
        std::string outfilename;
        opt.get("-o")->getString(outfilename);
        myfile.open(outfilename);
        
    }

    string line{};

    if (input.is_open())
    {
        while (getline(input, line))
        {
            if(output)
                myfile << line<<"\n";
            else
                cout << line << '\n';
        }
        input.close();
    }
    myfile.close();

    return 0;
}


/**********************************************************************************************//**
 * @fn	void showUsage(ezOptionParser& opt)
 *
 * @brief	Shows the usage for Target Orientation program.
 *
 * @param [in,out]	opt	The ezOptionParser object.
 **************************************************************************************************/

void showUsage(ezOptionParser& opt)
{
    std::string usage;
    opt.getUsage(usage);
    std::cout << usage;
}

/**********************************************************************************************//**
 * @fn	void initializeParser(ezOptionParser& opt)
 *
 * @brief	Initializes the ezOptionparser.CommandLine TargetOrientation.exe -h displays the Usage.
 *
 * @param [in,out]	opt	The ezOptionParser object.
 **************************************************************************************************/

void initializeParser(ezOptionParser& opt)
{
    opt.overview = "Basic Program";
    opt.syntax = "BasicProgram.exe [OPTIONS]";
    opt.example = "BasicProgram.exe -i \"abc.txt\" -o \"bca.txt\" \n\n";

    opt.add("", 0, 0, 0, "Display usage instructions", "-h", "--help");
    opt.add("", 0, 1, 0, "Output text file", "-o", "--output");
    opt.add("", 1, 1, 0, "Input text file", "-i", "--input");

}

/**********************************************************************************************//**
 * @fn	bool isMissingParams(ezOptionParser& opt)
 *
 * @brief	Query if 'opt' is missing parameters
 *
 * @param [in,out]	opt	The option.
 *
 * @returns	True if missing parameters, false if not.
 **************************************************************************************************/

bool isMissingParams(ezOptionParser& opt)
{
    std::vector<std::string> bad_options;
    bool has_reqd_args = opt.gotRequired(bad_options);
    return !has_reqd_args;
}

/**********************************************************************************************//**
 * @fn	void showProgramCall(ezOptionParser& opt)
 *
 * @brief	Shows the program call.
 *
 * @param [in,out]	opt	The ezOptionParser option.
 **************************************************************************************************/

void showProgramCall(ezOptionParser& opt)
{
    std::string filename;
    std::cout << "Starting Basic Program... " << std::endl;
    std::cout << "\t" << "BasicProgram.exe";


    opt.get("-i")->getString(filename);
    std::cout << " -i " << filename;

    opt.get("-o")->getString(filename);
    std::cout << " -o " << filename;

    std::cout << std::endl << std::endl;
}
