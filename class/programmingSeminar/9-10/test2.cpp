#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <math.h>
#include <time.h>
#include "EasyBMP.h"
/**
To Compile the Code use this command
g++ fileName.cpp EasyBMP.cpp -o outputFile
**/
#define N 1032
using namespace std;


void create_hologram(vector<vector<double> > object_points,double new_film[N][N], int size_op);
void float_range(double aray[], double start, double stop, double step );
void init_holofilm(double matrix[N][N], int demintion);
void create_bmp(double matrix[N][N], int demintion);
void pcd_paraer(string file_name, vector<vector<double> > &output);

int main()
{
   

    

    vector<vector<double> > op; 
    pcd_paraer("my_test1.obj", op);

    clock_t start, end;
    
    
    double film[N][N]={0.0};
    int size_of_objectPoints=op.size();
    cout<< size_of_objectPoints<<endl;


        start=clock();
  

        create_hologram(op, film, size_of_objectPoints);
        create_bmp(film,N);

        end=clock();

        cout<<end - start/CLOCKS_PER_SEC<<endl;
    
    return 0;
}



void create_hologram(vector<vector<double> > object_points, double new_film[N][N], int size_op)
{
    double wavelenght = 532e-9;//670e-9;
    double sampleing = 0.0254/N;
    double range = 0.0254/2;
    double pie2 = 2*M_PI;
    double optimze = pie2/wavelenght;
    
    double ipx[N];
    float_range(ipx,-1*range,range,sampleing);
    


    double ipy[N];
    float_range(ipy,-1*range,range,sampleing);




    for(int o=0;o<size_op;o++)
    {

        for(int i=0;i<N;i++)
        {
            for(int j=0; j < N;j++)
            {

                 double dx = object_points[o][0] - ipx[i];
                 double dy = object_points[o][1] - ipy[j];
                 double dz = object_points[o][2] - 0;
                 double distence= sqrt(dx*dx + dy*dy + dz*dz);
                 double wave= cos(distence*optimze);
                 new_film[i][j] = new_film[i][j]+wave;
                 j++;

                 dx = object_points[o][0] - ipx[i];
                 dy = object_points[o][1] - ipy[j];
                 dz = object_points[o][2] - 0;
                 distence= sqrt(dx*dx + dy*dy + dz*dz);
                 wave= cos(distence*optimze);
                 new_film[i][j] = new_film[i][j]+wave;
            }
        }
    }


    init_holofilm(new_film,N);




}

void float_range(double array[], double start, double stop, double step )
{   
    int counter=0;
    double i=start;

    while(i<stop)
        {
             array[counter]=i;

             counter++;
             i=i+step;
        }
}

void init_holofilm(double matrix[N][N], int demintion)
{

    double max=matrix[0][0];
    for(int i=0;i<demintion;i++)
    {
        for(int j=0;j<demintion;j++)
        {
            if(matrix[i][j]<0.5)
            {
               matrix[i][j]=0.0;
            }else
               matrix[i][j]=1.0;
        }

    }


}

void create_bmp(double matrix[N][N], int demintion)
{
    BMP anImage;
    anImage.SetSize(N,N);
    anImage.SetDPI(N,N);
    anImage.SetBitDepth(1);
    for(int i=0;i<N;i++)
    {
         for(int j=0;j<N;j++)
         {
             anImage(i,j)->Red=(matrix[i][j]*255);
             anImage(i,j)->Green=(matrix[i][j]*255);
             anImage(i,j)->Blue=(matrix[i][j]*255);
         }
    }

    anImage.WriteToFile("1200studentOutput.bmp");
    
}

void pcd_paraer(string file_name, vector<vector<double> > &output)
{
	int counter=1;
	char *temp_line;
	char *token;
	vector<double> line_holder;
        vector<double> line_holder2 (3);

      
	
	string line;
	ifstream in_file (file_name.c_str());
	
	if(in_file.is_open())
	{
		while(!in_file.eof())
		{
		    getline(in_file,line);

			
			if(counter > 11)
			{
				if(!(line.find("nan")))
				{
					

				}
				else
				{
				    temp_line= new char[line.length()+1];
		            strcpy(temp_line,line.c_str());
					token=strtok(temp_line,"\n ");
					while(token !=NULL){
						line_holder.push_back(atof(token));
					    token=strtok(NULL,"\n ");
					}

				}
		   }
			
			counter++;
		}

                counter=counter-13;
                for(int i=0;i<counter;i++)
                {
                    line_holder2[0]=line_holder[(1+4*i)];
                    line_holder2[1]=line_holder[(2+4*i)];
                    line_holder2[2]=line_holder[(3+4*i)];
                    output.push_back(line_holder2);
                }
	
	}

}
