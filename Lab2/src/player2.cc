//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "player2.h"

Define_Module(Player2);

void Player2::initialize()
{
}

void Player2::handleMessage(cMessage *msg)
{
    //Get the message content
    const char* msg_char_ptr = msg -> getName();
    if(strcmp(msg_char_ptr, "correct guess")==0){
        //terminate
        cancelAndDelete(msg);
    }
    else{
        //guess and send
        int random2 = par("random").intValue();
        // Convert the integer to a string.
        std::string random_str = std::to_string(random2);
        // Convert the string to a const char pointer.
        const char* random_char_ptr = random_str.c_str();
        //set the message name and send it
        msg->setName(random_char_ptr);
        send(msg, "out");
        //print the guess
        EV << random_char_ptr << endl;
    }
}
