package lab2;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=685,231");
    submodules:
        player1: Player1 {
            @display("p=414,61");
        }
        player2: Player2 {
            @display("p=100,61");
        }
    connections:
        player2.out --> player1.in;
        player1.out --> player2.in;
}

