#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	const char *fname="E:/MIL/VidClip1/VidClip1_frames.txt";
	ifstream strm; strm.open(fname, std::ios::in);
	if( strm.fail() ) return false;
	char * tline = new char[40000000];

	// get number of cols
	strm.getline( tline, 40000000 );
//	while( strtok(NULL," ,")!=NULL ) ncols++;
	
	// read in each row
	string str;
	strm.seekg( 0, ios::beg );
	while(!strm.eof() && strm.peek()>=0) { //  
		strm.getline( tline, 40000000 );
	//	strm>>str;
	//strm>>tline;
	cout<<"ffffffffffffffffffffffffffff"<<endl;
	}
	return 1;
}
