/*
 * This is a parser that will read in slimfly simulation output from ROSS and 
 * transform them into 3D visualizable data.
 *
 * The data provided is thanks to Noah Wolfe at RPI
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char * argv[]){

    // Give the boot if not used correctly
    if (argc != 6){
        printf("Improper Usage!\n");
        printf("Usage Example: ./parser -i <input_file> -o <send_output_file> <recv_output_file>\n");
        return 0;
    }

    printf("Starting parser program\n");
    std::ifstream inputFile;
    inputFile.open(argv[2]);

    if (!inputFile){
        printf("Unable to open: %s\n", argv[2]);
        return 0;
    }

    printf("Reading file: %s\n", argv[2]);

    std::vector< std::vector<int> >data_send;
    std::vector< std::vector<int> >data_recv;

    std::string line;
    int g_time;
    int entity;
    while (getline( inputFile, line ))
    {

        std::stringstream ss(line); 
        std::string strNum;
        unsigned int index = 0;
        unsigned int entityNum = 0;

        while (getline (ss, strNum, ',')){

            if ( index == 0 ) {

                // g_time is here
                g_time = atoi(strNum.c_str());

            } else if ( index % 2 == 1 ){

                // send data
                int rawData[] = {g_time,entityNum,atoi(strNum.c_str())}; // (x,y,z)
                std::vector<int> dataPoint (rawData, 
                        rawData + sizeof(rawData) / sizeof(int) ); 
                data_send.push_back(dataPoint);

            } else {
                // recv data
                int rawData[] = {g_time,entityNum,atoi(strNum.c_str())}; // (x,y,z)
                std::vector<int> dataPoint (rawData, 
                        rawData + sizeof(rawData) / sizeof(int) ); 
                data_recv.push_back(dataPoint);

                // next entity
                entityNum++;
            }

            // incr index
            index++;
        }
    }


    // Writing out the send data first
    printf("Writing file: %s\n",argv[4]);
    std::ofstream outputFileSend;
    outputFileSend.open(argv[4]);
    outputFileSend << "global_time, entity_id, frequency\n";
    for(int i = 0; i < data_send.size(); i++){
        outputFileSend << data_send[i][0] << ", " << data_send[i][1] 
            << ", " << data_send[i][2] << "\n";
    }

    // Writing out the recv data first
    printf("Writing file: %s\n",argv[5]);
    std::ofstream outputFileRecv;
    outputFileRecv.open(argv[5]);
    outputFileRecv << "global_time, entity_id, frequency\n";
    for(int i = 0; i < data_recv.size(); i++){
        outputFileRecv << data_recv[i][0] << ", " << data_recv[i][1] 
            << ", " << data_recv[i][2] << "\n";
    }

    printf("Done!\n");

    return 0;
}
