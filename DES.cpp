#include "header.h"
#include<iostream>
#include<string>
#include<math.h>
#include<cctype>
#include<conio.h>
#include<windows.h>
using namespace std;
string decToBin(int dec){
	int i=dec;
	string str="";
	//char binary[4];
     string binary = "";
	while(1){
		int quotient=i/2;
		int remainder=i%2;
		i=quotient;
		//itoa(remainder,binary,10);
        binary = to_string(remainder);
		str=str+binary;
		if(quotient==0)break;
	}
	string finalString="";
	for(int i=(str.length()-1);i>=0;i--){
		finalString=finalString+str[i];
	}
	return finalString;
}

int binToDec(string bin){	
	int dec=0,incr=0,sum=0;
	for(int i=(bin.length()-1);i>=0;i--){
		dec=bin[i]-'0';
		sum=sum+(int)(dec*(pow(2,incr)));
		incr++;
	}
	return sum;	
}

string stringProcess(string substring,int s[][4][16],int p){
	string row,col;
	for(int i=0;i<6;i++){
		if(i==0||i==5)row=row+substring[i];
		else{
			col=col+substring[i];
		}
	}
	int r=binToDec(row);
	int c=binToDec(col);
	int s_box_pos=s[p][r][c];
	string fbit_bin_str="0000";
	int len=decToBin(s_box_pos).length();
	string bin=decToBin(s_box_pos);

	for(int i=0;i<len;i++){
		fbit_bin_str[i+(4-len)]=bin[i];	
	}
	return fbit_bin_str;	
}

string keyFiftySix(string key,int pc1[8][7]){
	int i,j,k,bin_key_index=0,index=0;
	string fs_bin_key;
	
	for(k=0;k<56;k++)fs_bin_key=fs_bin_key+'0';
	for(i=0;i<8;i++){
		for(j=0;j<7;j++){
			index=pc1[i][j]-1;
			fs_bin_key[bin_key_index]=key[index];
			bin_key_index++;		
		}
	}
	return fs_bin_key;
}

string keyFourtyEight(string C,string D,int pc2[6][8]){		
	int fe_bin_key_index=0,concat_key_index=0,i,j,k;
	string binKey,concat_keys=C+D;
	for(i=0;i<48;i++)binKey=binKey+'0';
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			concat_key_index=pc2[i][j]-1;
		  	binKey[fe_bin_key_index]=concat_keys[concat_key_index];
		  	fe_bin_key_index++;		
		}
	}	
	return binKey;
}
string rollingKeys(string key,int rotatingSchedule[16],int i){	
	int count=rotatingSchedule[i],l,j,k;
	string rol_key;
	for(k=0;k<28;k++)rol_key=rol_key+'0';	
	while(count>0){
		for(l=0;l<28;l++){
			if(l==0)j=27;
			else{
				j=l-1;
			}
			rol_key[j]=key[l];
		}
		key=rol_key;
		count--;
	}	
	return rol_key;	
}
string permuInitialMsg(string msg,int ip[8][8]){	
	int ip_msg_index=0,msg_index=0,i,j;
	string ip_msg;
	for(i=0;i<64;i++)ip_msg=ip_msg+'0';	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			msg_index=ip[i][j]-1;
		  	ip_msg[ip_msg_index]=msg[msg_index];
		  	ip_msg_index++;		
		}
	}
	return ip_msg;
}

string expandedMsg(string R,int ep[8][6]){
	int ep_msg_index=0,R_index=0,i,j;
	string ep_msg;
	for(i=0;i<48;i++)ep_msg=ep_msg+'0';
	for(i=0;i<8;i++){
		for(j=0;j<6;j++){
			R_index=ep[i][j]-1;
			ep_msg[ep_msg_index]=R[R_index];
			ep_msg_index++;		
		}
	}
	return ep_msg;	
}

string xorMsg(string ep_msg,string fe_key){	
	int xor_val,i,len=ep_msg.length();
	//char holder[len];
	string holder;
	string xorMsg;
	
	for(i=0;i<len;i++){
		xor_val=((fe_key[i]-'0')^(ep_msg[i]-'0'));
		//itoa(xor_val,holder,10);
		//holder = decToBin(xor_val);
        holder = to_string(xor_val);
		xorMsg=xorMsg+holder;
	}	
	return xorMsg;	
}

string substitutionMethod(string xored_message,int sbox[][4][16]){
	string thirty_two_bit_msg;	
	int index=0,len=6;
	for(int i=0;i<48;i+=6){
		thirty_two_bit_msg=thirty_two_bit_msg+stringProcess(xored_message.substr(i,len),sbox,index);
		index++;	
	}
	return thirty_two_bit_msg;
}

string permutedMsg(string thirty_two_bit_msg,int pf[4][8]){
	int index=0,thirty_two_bit_msg_index=0,i,j;
	string permuted_msg;
	for(i=0;i<thirty_two_bit_msg.length();i++)permuted_msg=permuted_msg+'0';
	for(i=0;i<4;i++){
		for(j=0;j<8;j++){
     	  		thirty_two_bit_msg_index=pf[i][j]-1;
		  	permuted_msg[index]=thirty_two_bit_msg[thirty_two_bit_msg_index];
		  	index++;	
		}
	}
	return permuted_msg;
}

string hexConversion(string de_msg,string conversionTable[23],string hex[23]){
	int len=4;
	string substring="",hex_message="";		
	for(int i=0;i<64;i+=4){
		int find=0;
		substring=de_msg.substr(i,len);
		while(1){		
			if(conversionTable[find]==substring)break;	
			find++;	
		}
		hex_message=hex_message+hex[find];
	}
	return hex_message;	
}

string inverseIPmsg(string reversedMsg,int inv_ip[8][8]){
	string inv_msg="";
	int inv_msg_index=0,index=0,i,j;
	for(i=0;i<64;i++)inv_msg=inv_msg+'0';
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			index=inv_ip[i][j]-1;
		  	inv_msg[inv_msg_index]=reversedMsg[index];
		  	inv_msg_index++;	
		}
	}
	return inv_msg;
}

string desMethod(string message,string key,bool encrypt){
	string conversionTable[23]={
   		"0000",
	    	"0001",
   		"0010",
   		"0011",
   		"0100",
   		"0101",
   		"0110",
   		"0111",
   		"1000",
   		"1001",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
	    	"1010",
   		"1011",
   		"1100",
   		"1101",
   		"1110",
   		"1111"	
   };
   
   string hex[23]={
   		"0",
   		"1",
   		"2",
   		"3",
   		"4",
   		"5",
   		"6",
   		"7",
   		"8",
   		"9",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"A",
   		"B",
   		"C",
   		"D",
   		"E",
   		"F"   	
   };

     int inv_ip[8][8]={   					
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9,  49, 17, 57, 25	
   };
   
   int ip[8][8]={
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9,  1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7	
   };
   
 
   
     int pf[4][8]={					
		16, 7, 20, 21, 29, 12, 28, 17,
		1, 15, 23, 26, 5,  18, 31, 10,
		2, 8,  24, 14, 32, 27, 3,  9,
		19,13, 30, 6,  22, 11, 4,  25
   };
   

   int ep[8][6]={
		32, 1, 2, 3, 4, 5,
		4,  5, 6, 7, 8, 9,
		8,  9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32, 1
   };
   
 
   int sbox[8][4][16]={
   	{
		14, 4, 13, 1, 2, 15, 11, 8, 3,  10, 6,  12, 5, 9,  0, 7,
	     	0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12,  11, 9, 5,  3, 8,
		 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9,   7, 3, 10, 5, 0,
		15, 12, 8, 2,  4, 9, 1,  7, 5,  11, 3,  14, 10, 0, 6, 13
    	},
	{
		15, 1, 8, 14, 6, 11, 3,  4,  9,  7, 2, 13, 12,  0, 5, 10,
            	3, 13, 4, 7,  15, 2, 8, 14, 12,  0, 1, 10,  6,  9, 11, 5,
            	0, 14, 7, 11, 10, 4, 13, 1,  5,  8, 12, 6,  9,  3,  2, 15,
            	13, 8, 10, 1, 3, 15, 4,  2, 11,  6, 7, 12,  0,  5, 14,  9
	},
	{
		10, 0, 9, 14, 6, 3, 15, 5,  1, 13, 12, 7, 11, 4,  2,  8,
		13, 7, 0, 9,  3, 4,  6, 10, 2, 8,  5, 14, 12, 11, 15, 1,
		13, 6, 4, 9,  8, 15, 3, 0, 11, 1,  2, 12, 5,  10, 14, 7,
		1, 10, 13, 0, 6, 9,  8, 7,  4, 15, 14, 3, 11, 5,  2, 12
	},
	{
		7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
	    	13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
		10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
		3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
	},
	{
		2,  12, 4, 1,  7, 10, 11, 6, 8, 5, 3,  15, 13, 0, 14, 9,
		14, 11, 2, 12, 4, 7,  13, 1, 5, 0, 15, 10, 3,  9, 8,  6,
		4,  2,  1, 11, 10,13, 7,  8, 15,9, 12, 5,  6,  3, 0,  14,
		11, 8, 12, 7,  1, 14, 2, 13, 6, 15, 0, 9,  10, 4, 5,  3
	},
	{
	    	12, 1, 10, 15,9, 2, 6, 8, 0, 13, 3, 4, 14, 7,  5, 11,
		10, 15, 4, 2, 7, 12,9, 5, 6, 1, 13, 14, 0, 11, 3,  8,
		9,  14,15, 5, 2, 8, 12,3, 7, 0, 4,  10, 1, 13, 11, 6,
		4,  3,  2, 12,9, 5, 15,10,11,14,1,  7,  6, 0,  8, 13
	},
	{
	    	4, 11, 2,  14, 15, 0, 8, 13, 3,  12, 9, 7,  5, 10, 6, 1,
	       	13, 0,  11, 7,  4,  9, 1, 10, 14,  3, 5, 12, 2, 15, 8, 6,
		1, 4,  11, 13, 12, 3, 7, 14, 10, 15, 6,  8, 0,  5, 9, 2,
		6, 11, 13, 8,  1,  4, 10, 7, 9,  5,  0, 15, 14, 2, 3, 12
	},
	{
	 	13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3,  14, 5, 0, 12, 7,
		 1, 15,13, 8, 10, 3, 7,  4, 12, 5, 6,  11, 0, 14, 9, 2,
	     	7, 11, 4, 1, 9, 12, 14, 2,  0, 6, 10, 13, 15, 3, 5, 8,
	     	2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9,  0, 3,  5, 6, 11
	}
   };
  
  int pc1[8][7]={
	57, 49, 41, 33, 25, 17, 9,
	1,  58, 50, 42, 34, 26, 18,
	 10, 2,  59, 51, 43, 35, 27,
    	19, 11, 3,  60, 52, 44, 36,
    	63, 55, 47, 39, 31, 23, 15,
    	7,  62, 54, 46, 38, 30, 22,
    	14, 6,  61, 53, 45, 37, 29,
    	21, 13, 5,  28, 20, 12, 4
  };
 
  int pc2[6][8]={
	14, 17, 11, 24, 1,  5,  3, 28,
	15, 6,  21, 10, 23, 19, 12, 4,
	26, 8,  16, 7,  27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32
  };

  int rotatingSchedule[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    /*necessary tables initialization ends*/
    /*hexadecimal msg and key input and conversion to binary starts*/
 
  /*hexadecimal msg and key input and conversion to binary ends*/
	
   	/*Key processing starts*/

  string fs_key = keyFiftySix(key,pc1);

  string ip_msg = permuInitialMsg(message,ip);


  string Lo = ip_msg.substr(0,32);
  

  string Ro = ip_msg.substr(32,64);
  

  string Co = fs_key.substr(0,28);

  string Do = fs_key.substr(28,56);

  int round=16;
  string key_holder[round],fe_key;
  for(int i=0;i<round;i++){
  	int iteration=i;
  	string C1=rollingKeys(Co,rotatingSchedule,iteration%round);
   	string D1=rollingKeys(Do,rotatingSchedule,iteration%round);   
   
   	fe_key=keyFourtyEight(C1,D1,pc2);
   	key_holder[i]=fe_key;
	      		
        Co=C1;
   	Do=D1;		   /*key processing ends*/
   }

   int i=0;      
   while(round>0){
    	Sleep(500);
	
    	string ep_msg=expandedMsg(Ro,ep); 
	
    	if(encrypt==false){
    		fe_key="";
    		for(int j=0;j<48;j++)fe_key=fe_key+key_holder[round-1][j];

      	}
      	else{
      		fe_key="";
		for(int j=0;j<48;j++)fe_key=fe_key+key_holder[i][j];

    	}
      
	string xored_message=xorMsg(ep_msg,fe_key);

    
    	string substituted_msg=substitutionMethod(xored_message,sbox);
   
    
    	string permuted_msg=permutedMsg(substituted_msg,pf);

    
    	string L1=Ro;
    	
	
    	string R1=xorMsg(Lo,permuted_msg);
   
    
    	Lo=L1;
    	Ro=R1;
        i++;
    	round--;
    		    	    
     }

     string reversedMsg=Ro+Lo;

     string des_encrypted_msg=inverseIPmsg(reversedMsg,inv_ip);
   
     return des_encrypted_msg;
}
bool inputVerifier(string message){
	 
	 string hex_standard="0123456789ABCDEF";
	 int count=0,found=0;
	 for(int i=0;i<message.length();i++){
	 	for(int j=0;j<hex_standard.length();j++){
  	    		if(message[i]==hex_standard[j])count++;	
  	    } 	
	 }
	 
	 if(count==message.length())found=1;	
	 if(message.length()>16||message.length()<16||found==0){ 
	 	return false;
	 }
	 else{
		return true;
	 }
}			
string des(string message, bool flag){
         
		 string key="0001001100110100010101110111100110011011101111001101111111110001";
			string  encrypted_msg,secretMessage = "" , decrypted_msg, subString = "";

		   if(flag == true){

			int size = message.length()/64;
			int remain = message.length()%64;
            int save = remain;
            int r;
			
	//		int start = 0;
	int start = 0;
			for(int i = 0;i<size;i++){
				subString = message.substr(start,64);
			    start += 64;
				secretMessage += desMethod(subString,key, flag);
				subString = "";
			}

            if(save != 0){
			int initial = (size*64) ;   //???? -1
			subString = "";
			subString = message.substr(initial, save);

			
			for(int i = 0;i<64-save;i++){
				subString += "0";
			}
			secretMessage += desMethod(subString,key,flag);

        int min[6];
         for(int i= 0;i<6;i++){
				min[i] = remain % 2;
                //
				remain = remain / 2;
				
			}
			for(int i = 5;i>=0;i--){
				secretMessage += (char)min[i] + '0';
			}
			
			}
		   }
			
			else if(flag == false){
                   int min[6];
				   int index = 0, number = 0;
				   int length = message.length()-1;         //
				     for(int i= 0;i<6;i++){
						 min[i] = (int)message[length--] - '0';    //
						 number += pow(2,index) * min[i];
						 
						 index++;
					 }
					 int start = 0;  
					 int size = (message.length()-6)/64;   ///
			
			    for(int i = 0;i<size;i++){
				subString = message.substr(start,64);
			    start += 64;
				secretMessage += desMethod(subString,key, flag);

				subString = "";
			}
			secretMessage.erase(secretMessage.length()-(64-number)+1);
			}
           cout<<endl;	
 	return secretMessage;
}
