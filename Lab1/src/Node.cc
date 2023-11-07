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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    if(strcmp(getName(),"Tic")==0)
    {
        cMessage *msg = new cMessage ("Tic_0");
        send(msg, "out");
    }
}

void Node::handleMessage(cMessage *msg)
{
    if(count<9)
    {
            count++;
            // Convert the integer to a string.
            std::string intStr = "_" + std::to_string(count);
            // Concat the Node name to the counter.
            std::string my_string = getName() + intStr;
            // Convert the string to a const char pointer.
            const char* my_char_ptr = my_string.c_str();
            // Set the message's name.
            msg->setName(my_char_ptr);
            // Send the message to the out gate.
            send(msg, "out");

            EV << "Resending message" << endl;
    }
}
