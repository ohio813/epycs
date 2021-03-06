//
// Util.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////////////////////////////////
// Calculate crc32 for 41 ?
/////////////////////////////////
unsigned short word_9A8844[]={
0x0000,0x1021,0x2042,0x3063,0x4084,0x50A5,0x60C6,0x70E7,
0x8108,0x9129,0xA14A,0xB16B,0xC18C,0xD1AD,0xE1CE,0xF1EF,
0x1231,0x0210,0x3273,0x2252,0x52B5,0x4294,0x72F7,0x62D6,
0x9339,0x8318,0xB37B,0xA35A,0xD3BD,0xC39C,0xF3FF,0xE3DE,
0x2462,0x3443,0x0420,0x1401,0x64E6,0x74C7,0x44A4,0x5485,
0xA56A,0xB54B,0x8528,0x9509,0xE5EE,0xF5CF,0xC5AC,0xD58D,
0x3653,0x2672,0x1611,0x0630,0x76D7,0x66F6,0x5695,0x46B4,
0xB75B,0xA77A,0x9719,0x8738,0xF7DF,0xE7FE,0xD79D,0xC7BC,
0x48C4,0x58E5,0x6886,0x78A7,0x0840,0x1861,0x2802,0x3823,
0xC9CC,0xD9ED,0xE98E,0xF9AF,0x8948,0x9969,0xA90A,0xB92B,
0x5AF5,0x4AD4,0x7AB7,0x6A96,0x1A71,0x0A50,0x3A33,0x2A12,
0xDBFD,0xCBDC,0xFBBF,0xEB9E,0x9B79,0x8B58,0xBB3B,0xAB1A,
0x6CA6,0x7C87,0x4CE4,0x5CC5,0x2C22,0x3C03,0x0C60,0x1C41,
0xEDAE,0xFD8F,0xCDEC,0xDDCD,0xAD2A,0xBD0B,0x8D68,0x9D49,
0x7E97,0x6EB6,0x5ED5,0x4EF4,0x3E13,0x2E32,0x1E51,0x0E70,
0xFF9F,0xEFBE,0xDFDD,0xCFFC,0xBF1B,0xAF3A,0x9F59,0x8F78,
0x9188,0x81A9,0xB1CA,0xA1EB,0xD10C,0xC12D,0xF14E,0xE16F,
0x1080,0x00A1,0x30C2,0x20E3,0x5004,0x4025,0x7046,0x6067,
0x83B9,0x9398,0xA3FB,0xB3DA,0xC33D,0xD31C,0xE37F,0xF35E,
0x02B1,0x1290,0x22F3,0x32D2,0x4235,0x5214,0x6277,0x7256,
0xB5EA,0xA5CB,0x95A8,0x8589,0xF56E,0xE54F,0xD52C,0xC50D,
0x34E2,0x24C3,0x14A0,0x0481,0x7466,0x6447,0x5424,0x4405,
0xA7DB,0xB7FA,0x8799,0x97B8,0xE75F,0xF77E,0xC71D,0xD73C,
0x26D3,0x36F2,0x0691,0x16B0,0x6657,0x7676,0x4615,0x5634,
0xD94C,0xC96D,0xF90E,0xE92F,0x99C8,0x89E9,0xB98A,0xA9AB,
0x5844,0x4865,0x7806,0x6827,0x18C0,0x08E1,0x3882,0x28A3,
0xCB7D,0xDB5C,0xEB3F,0xFB1E,0x8BF9,0x9BD8,0xABBB,0xBB9A,
0x4A75,0x5A54,0x6A37,0x7A16,0x0AF1,0x1AD0,0x2AB3,0x3A92,
0xFD2E,0xED0F,0xDD6C,0xCD4D,0xBDAA,0xAD8B,0x9DE8,0x8DC9,
0x7C26,0x6C07,0x5C64,0x4C45,0x3CA2,0x2C83,0x1CE0,0x0CC1,
0xEF1F,0xFF3E,0xCF5D,0xDF7C,0xAF9B,0xBFBA,0x8FD9,0x9FF8,
0x6E17,0x7E36,0x4E55,0x5E74,0x2E93,0x3EB2,0x0ED1,0x1EF0,
}
;




////////////////////////////////
//calculate crc32
/////////////////////////////////
//crc table
//1024 bytes
//+16

char CRC_32_Table[]=
"\x00\x00\x00\x00\x96\x30\x07\x77\x2C\x61\x0E\xEE\xBA\x51\x09\x99"
"\x19\xC4\x6D\x07\x8F\xF4\x6A\x70\x35\xA5\x63\xE9\xA3\x95\x64\x9E"
"\x32\x88\xDB\x0E\xA4\xB8\xDC\x79\x1E\xE9\xD5\xE0\x88\xD9\xD2\x97"
"\x2B\x4C\xB6\x09\xBD\x7C\xB1\x7E\x07\x2D\xB8\xE7\x91\x1D\xBF\x90"
"\x64\x10\xB7\x1D\xF2\x20\xB0\x6A\x48\x71\xB9\xF3\xDE\x41\xBE\x84"
"\x7D\xD4\xDA\x1A\xEB\xE4\xDD\x6D\x51\xB5\xD4\xF4\xC7\x85\xD3\x83"
"\x56\x98\x6C\x13\xC0\xA8\x6B\x64\x7A\xF9\x62\xFD\xEC\xC9\x65\x8A"
"\x4F\x5C\x01\x14\xD9\x6C\x06\x63\x63\x3D\x0F\xFA\xF5\x0D\x08\x8D"
"\xC8\x20\x6E\x3B\x5E\x10\x69\x4C\xE4\x41\x60\xD5\x72\x71\x67\xA2"
"\xD1\xE4\x03\x3C\x47\xD4\x04\x4B\xFD\x85\x0D\xD2\x6B\xB5\x0A\xA5"
"\xFA\xA8\xB5\x35\x6C\x98\xB2\x42\xD6\xC9\xBB\xDB\x40\xF9\xBC\xAC"
"\xE3\x6C\xD8\x32\x75\x5C\xDF\x45\xCF\x0D\xD6\xDC\x59\x3D\xD1\xAB"
"\xAC\x30\xD9\x26\x3A\x00\xDE\x51\x80\x51\xD7\xC8\x16\x61\xD0\xBF"
"\xB5\xF4\xB4\x21\x23\xC4\xB3\x56\x99\x95\xBA\xCF\x0F\xA5\xBD\xB8"
"\x9E\xB8\x02\x28\x08\x88\x05\x5F\xB2\xD9\x0C\xC6\x24\xE9\x0B\xB1"
"\x87\x7C\x6F\x2F\x11\x4C\x68\x58\xAB\x1D\x61\xC1\x3D\x2D\x66\xB6"
"\x90\x41\xDC\x76\x06\x71\xDB\x01\xBC\x20\xD2\x98\x2A\x10\xD5\xEF"
"\x89\x85\xB1\x71\x1F\xB5\xB6\x06\xA5\xE4\xBF\x9F\x33\xD4\xB8\xE8"
"\xA2\xC9\x07\x78\x34\xF9\x00\x0F\x8E\xA8\x09\x96\x18\x98\x0E\xE1"
"\xBB\x0D\x6A\x7F\x2D\x3D\x6D\x08\x97\x6C\x64\x91\x01\x5C\x63\xE6"
"\xF4\x51\x6B\x6B\x62\x61\x6C\x1C\xD8\x30\x65\x85\x4E\x00\x62\xF2"
"\xED\x95\x06\x6C\x7B\xA5\x01\x1B\xC1\xF4\x08\x82\x57\xC4\x0F\xF5"
"\xC6\xD9\xB0\x65\x50\xE9\xB7\x12\xEA\xB8\xBE\x8B\x7C\x88\xB9\xFC"
"\xDF\x1D\xDD\x62\x49\x2D\xDA\x15\xF3\x7C\xD3\x8C\x65\x4C\xD4\xFB"
"\x58\x61\xB2\x4D\xCE\x51\xB5\x3A\x74\x00\xBC\xA3\xE2\x30\xBB\xD4"
"\x41\xA5\xDF\x4A\xD7\x95\xD8\x3D\x6D\xC4\xD1\xA4\xFB\xF4\xD6\xD3"
"\x6A\xE9\x69\x43\xFC\xD9\x6E\x34\x46\x88\x67\xAD\xD0\xB8\x60\xDA"
"\x73\x2D\x04\x44\xE5\x1D\x03\x33\x5F\x4C\x0A\xAA\xC9\x7C\x0D\xDD"
"\x3C\x71\x05\x50\xAA\x41\x02\x27\x10\x10\x0B\xBE\x86\x20\x0C\xC9"
"\x25\xB5\x68\x57\xB3\x85\x6F\x20\x09\xD4\x66\xB9\x9F\xE4\x61\xCE"
"\x0E\xF9\xDE\x5E\x98\xC9\xD9\x29\x22\x98\xD0\xB0\xB4\xA8\xD7\xC7"
"\x17\x3D\xB3\x59\x81\x0D\xB4\x2E\x3B\x5C\xBD\xB7\xAD\x6C\xBA\xC0"
"\x20\x83\xB8\xED\xB6\xB3\xBF\x9A\x0C\xE2\xB6\x03\x9A\xD2\xB1\x74"
"\x39\x47\xD5\xEA\xAF\x77\xD2\x9D\x15\x26\xDB\x04\x83\x16\xDC\x73"
"\x12\x0B\x63\xE3\x84\x3B\x64\x94\x3E\x6A\x6D\x0D\xA8\x5A\x6A\x7A"
"\x0B\xCF\x0E\xE4\x9D\xFF\x09\x93\x27\xAE\x00\x0A\xB1\x9E\x07\x7D"
"\x44\x93\x0F\xF0\xD2\xA3\x08\x87\x68\xF2\x01\x1E\xFE\xC2\x06\x69"
"\x5D\x57\x62\xF7\xCB\x67\x65\x80\x71\x36\x6C\x19\xE7\x06\x6B\x6E"
"\x76\x1B\xD4\xFE\xE0\x2B\xD3\x89\x5A\x7A\xDA\x10\xCC\x4A\xDD\x67"
"\x6F\xDF\xB9\xF9\xF9\xEF\xBE\x8E\x43\xBE\xB7\x17\xD5\x8E\xB0\x60"
"\xE8\xA3\xD6\xD6\x7E\x93\xD1\xA1\xC4\xC2\xD8\x38\x52\xF2\xDF\x4F"
"\xF1\x67\xBB\xD1\x67\x57\xBC\xA6\xDD\x06\xB5\x3F\x4B\x36\xB2\x48"
"\xDA\x2B\x0D\xD8\x4C\x1B\x0A\xAF\xF6\x4A\x03\x36\x60\x7A\x04\x41"
"\xC3\xEF\x60\xDF\x55\xDF\x67\xA8\xEF\x8E\x6E\x31\x79\xBE\x69\x46"
"\x8C\xB3\x61\xCB\x1A\x83\x66\xBC\xA0\xD2\x6F\x25\x36\xE2\x68\x52"
"\x95\x77\x0C\xCC\x03\x47\x0B\xBB\xB9\x16\x02\x22\x2F\x26\x05\x55"
"\xBE\x3B\xBA\xC5\x28\x0B\xBD\xB2\x92\x5A\xB4\x2B\x04\x6A\xB3\x5C"
"\xA7\xFF\xD7\xC2\x31\xCF\xD0\xB5\x8B\x9E\xD9\x2C\x1D\xAE\xDE\x5B"
"\xB0\xC2\x64\x9B\x26\xF2\x63\xEC\x9C\xA3\x6A\x75\x0A\x93\x6D\x02"
"\xA9\x06\x09\x9C\x3F\x36\x0E\xEB\x85\x67\x07\x72\x13\x57\x00\x05"
"\x82\x4A\xBF\x95\x14\x7A\xB8\xE2\xAE\x2B\xB1\x7B\x38\x1B\xB6\x0C"
"\x9B\x8E\xD2\x92\x0D\xBE\xD5\xE5\xB7\xEF\xDC\x7C\x21\xDF\xDB\x0B"
"\xD4\xD2\xD3\x86\x42\xE2\xD4\xF1\xF8\xB3\xDD\x68\x6E\x83\xDA\x1F"
"\xCD\x16\xBE\x81\x5B\x26\xB9\xF6\xE1\x77\xB0\x6F\x77\x47\xB7\x18"
"\xE6\x5A\x08\x88\x70\x6A\x0F\xFF\xCA\x3B\x06\x66\x5C\x0B\x01\x11"
"\xFF\x9E\x65\x8F\x69\xAE\x62\xF8\xD3\xFF\x6B\x61\x45\xCF\x6C\x16"
"\x78\xE2\x0A\xA0\xEE\xD2\x0D\xD7\x54\x83\x04\x4E\xC2\xB3\x03\x39"
"\x61\x26\x67\xA7\xF7\x16\x60\xD0\x4D\x47\x69\x49\xDB\x77\x6E\x3E"
"\x4A\x6A\xD1\xAE\xDC\x5A\xD6\xD9\x66\x0B\xDF\x40\xF0\x3B\xD8\x37"
"\x53\xAE\xBC\xA9\xC5\x9E\xBB\xDE\x7F\xCF\xB2\x47\xE9\xFF\xB5\x30"
"\x1C\xF2\xBD\xBD\x8A\xC2\xBA\xCA\x30\x93\xB3\x53\xA6\xA3\xB4\x24"
"\x05\x36\xD0\xBA\x93\x06\xD7\xCD\x29\x57\xDE\x54\xBF\x67\xD9\x23"
"\x2E\x7A\x66\xB3\xB8\x4A\x61\xC4\x02\x1B\x68\x5D\x94\x2B\x6F\x2A"
"\x37\xBE\x0B\xB4\xA1\x8E\x0C\xC3\x1B\xDF\x05\x5A\x8D\xEF\x02\x2D"
"\x00\x00\x21\x10\x42\x20\x63\x30\x84\x40\xA5\x50\xC6\x60\xE7\x70"
;


unsigned int Calculate_CRC32(char *crc32, int bytes) {
  unsigned int esi_var;
  unsigned int eax,ebx,ecx,ecx1;
  int i;

  esi_var = -1;
  i=bytes;

  if (bytes) {
	  do {
		eax=esi_var;
		ebx=0;
		ebx=crc32[0] & 0xff;
		ecx=eax;
		ecx=ecx & 0xff;
		ecx=ecx ^ ebx;
		eax=eax >> 8;
		memcpy((char *)&ecx1,(char *)CRC_32_Table+ecx*4,4);
		ecx=ecx1;		
		ecx=ecx ^ eax;
		crc32++;
		i--;
		esi_var=ecx;
	  }while(i);
  };

  return esi_var;

};

///////////////////////////////////////////////////////////////////////////
// Calculate crc32 for 41 ?
///////////////////////////////////////////////////////////////////////////
int Calculate_CRC32_For41(char *data, int len)
{

  unsigned short ret = 0;
  unsigned short current, tmp;

  while (len > 0)
  {
	  current = data[0] & 0xFF;

	  current = current ^ (ret >> 8);

	  tmp = word_9A8844[current];
	  ret <<= 8;
	  ret = ret ^ tmp;

	  data++;
	  len --;

  }

  return ret;
}


