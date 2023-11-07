package lab1;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=593,200");
    submodules:
        Tic: Node {
            @display("p=70,82");
        }
        Toc: Node {
            @display("p=370,82");
        }
    connections:
        Tic.out --> Toc.in;
        Toc.out --> Tic.in;
}

