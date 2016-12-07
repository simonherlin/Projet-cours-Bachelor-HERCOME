#include "CER433Arduino.h"

CER433Arduino::CER433Arduino(int PinEmetteur, int PinRecepteur)
{
    vw_set_rx_pin(2);
    vw_setup(2000);  // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
}

CER433Arduino::~CER433Arduino()
{

}

bool CER433Arduino::Receive(char* trame)
{
   Serial.println("RECEIVE");
    if (vw_get_message(this->buf, &this->buflen)) // Non-blocking
    {
      Serial.println((char*)this->buf);
      if(buf[0] == 0x02 && buf[8] == 0x03)
      {
        
        strcpy(trame,(char*)this->buf);
        return true;
      }
      else
      {
        return false;
      }
        
    }
   
}


void CER433Arduino::Send(char * trame)
{
  vw_send(trame, strlen(trame));
  vw_wait_tx(); // Wait until the whole message is gone
}
