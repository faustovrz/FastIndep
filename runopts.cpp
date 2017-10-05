// Test for including command line options in fastindep

#include "./headers.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <cerrno>
#include <algorithm>
#include <functional>

// Options libs
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char **argv)
{
    double lowLDlimit = numeric_limits<double>::quiet_NaN();
    int num_sweeps = 0;
    bool seed_specified = false;
    unsigned long longseed = 0;
    string outputfile = "outfile.txt";
    string datafile = "infile.txt";
    int index;
    int opt;

    opterr = 0;

    while ((opt = getopt (argc, argv, "t:n:s:i:o:")) != EOF)
        switch (opt)
        {
        case 't':
            lowLDlimit = atof(optarg);
            break;
        case 'n':
            num_sweeps = atof(optarg);
            break;
        case 's':
            seed_specified = true;
            longseed = atof(optarg);
            break;
        case 'o':
            outputfile = string(optarg);
        case 'i':
            datafile = string(optarg);
            break;
        case '?':
            if (optopt == 't')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr,
                         "Unknown option character `\\x%x'.\n",
                         optopt);
            return 1;
        default:
            abort ();
        }

    fprintf (stderr, "lowLDlimit = %f, num_sweeps = %d, longseed = %lu\n",
            lowLDlimit, num_sweeps, longseed);
    // string datafile = argv[optind]; //assumes last agrument 
    fprintf (stderr, "datafile = %s\n",datafile.c_str());
    for (index = optind ; index < argc; index++)
        fprintf (stderr, "Non-option argument %s ignored \n", argv[index]);
    return 0;
}