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

#include "player1.h"

Define_Module(Player1);


void Player1::initialize()
{
   //Get the parameter
   random1 = par("random").intValue();
   // Convert the random number to a char pointer.
   rand_str = std::to_string(random1);
   rand_char_ptr = rand_str.c_str();
    EV << random1 << endl;
    cMessage *msg = new cMessage ("Start Guessing");
    send(msg, "out");
}

void Player1::handleMessage(cMessage *msg)
{
    //Get the message content
    const char* guess_char_ptr = msg -> getName();
    //Compare the guess with the initial number
    if(strcmp(guess_char_ptr,rand_char_ptr )==0)
    {
        msg->setName("correct guess");
    }
    else{
        msg->setName("wrong guess");
    }
    EV << msg->getName() << endl;
    send(msg, "out");
}
