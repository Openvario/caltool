/*  
	caltool - Touch screen calibration tool for XCSoar Glide Computer - http://www.openvario.org/
    Copyright (C) 2014  The openvario project
    A detailed list of copyright holders can be found in the file "AUTHORS" 

    This program is free software; you can redistribute it and/or 
    modify it under the terms of the GNU General Public License 
    as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, see <http://www.gnu.org/licenses/>.	
*/

#include "version.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void cmdline_parser(int argc, char **argv, int *rotation, int *use_calfile, char *cal_file){

	// locale variables
	int c;
	int rot;
	
	const char* Usage = "\n"\
    "  -v              			print version information\n"\
	"  -c [calibration file]	specify file for calibration\n" \
	"  -r [rotation]   			sets rotation of touch calibration default=landscape \n"\
	"\n";
	
	// check commandline arguments
	while ((c = getopt (argc, argv, "vr:c:")) != -1)
	{
		switch (c) {
			case 'v':
				//sprintf(s, "sensord V0.1 %s %s", __DATE__
				printf("caltool V%c.%c RELEASE %c build: %s %s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_RELEASE,  __DATE__, __TIME__);
				printf("caltool  Copyright (C) 2015  see AUTHORS on www.openvario.org\n");
				printf("This program comes with ABSOLUTELY NO WARRANTY;\n");
				printf("This is free software, and you are welcome to redistribute it under certain conditions;\n"); 
				exit(EXIT_FAILURE);
				break;
			// calibration file
			case 'c':
				if (optarg != NULL)
				{
					strcpy(cal_file, optarg);
				}
				else
				{
					printf("Error: Argument needed !!\n");
					printf("Exiting ...\n");
					exit(EXIT_FAILURE);
				}
			break;
			// screen rotation
			case 'r':
				if (optarg != NULL)
				{
					// convert input parameter to string
					rot = atoi(optarg);
					switch (rot){
						case 0:
						case 1:
						case 2:
						case 3:
							*rotation = rot;
							break;
						default:
							printf("Error: Unknown argument for -r !!\n");
							printf("Exiting ...\n");
							exit(EXIT_FAILURE);
							break;	
					}
					*use_calfile = 1;
				}
				else
				{
					printf("Error: Unknown argument for -r !!\n");
					printf("Exiting ...\n");
					exit(EXIT_FAILURE);
				}
				break;
			
			case '?':
				printf("Unknow option %c\n", optopt);
				printf("Usage: caltool [OPTION]\n%s",Usage);
				printf("Exiting ...\n");
				exit(EXIT_FAILURE);
				break;
		}
	}
}
	