#include "VirtualWire.h"

class CER433Arduino
	{
	public:
		CER433Arduino(int PinEmetteur, int PinRecepteur);
		~CER433Arduino();
		void Send(char* Message);
		bool Receive(char* Trame);
  private: 
    uint8_t buf[9];
   uint8_t buflen = 9;
	};
