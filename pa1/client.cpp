/*
    Tanzir Ahmed
    Department of Computer Science & Engineering
    Texas A&M University
    Date  : 2/8/20
 */
#include "common.h"
#include "FIFOreqchannel.h"

using namespace std;


int main(int argc, char *argv[]){
    FIFORequestChannel chan ("control", FIFORequestChannel::CLIENT_SIDE);

    // sending a non-sense message, you need to change this
    char buf [MAX_MESSAGE];
    datamsg* x = new datamsg (10, 0.004, 2);
	
	chan.cwrite (x, sizeof (datamsg));
	int nbytes = chan.cread (buf, MAX_MESSAGE);
	double reply = *(double *) buf;
    cout << "For person 10, at time 0.004, the value of ech 2 is " << reply << endl;
	
	/*filemsg fm (0,0);
	string fname = "teslkansdlkjflasjdf.dat";
	
	char buf2 [sizeof (filemsg) + fname.size()+1];
	memcpy (buf2, &fm, sizeof (filemsg));
	strcpy (buf2 + sizeof (filemsg), fname.c_str());
	*/
	
	// closing the channel    
    MESSAGE_TYPE m = QUIT_MSG;
    chan.cwrite (&m, sizeof (MESSAGE_TYPE));
}
