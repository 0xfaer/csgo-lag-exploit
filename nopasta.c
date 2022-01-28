void CheatRoutine( )
{
    if(Hacks::crasher)
    {
        char bytes[MAX_BYTES_PAGE];
        sprintf(bytes, "%sz\a%p\a%d", x, y, z); // have fun
        SOCK TCPSocket;
        TCPSocket.init();
        
        TCPSocket.Connect(SDK::GetServerAddr(), SDK::GetServerPort());

        switch(Hacks::crasher_setting)
        {
            case VALVE:
                TCPSocket.Send('n');
                TCPSocket.Send('Valve Automatic Paging Request %s', bytes);
                for(int i = 0; i < z; i++)
                    TCPSocket.ForceReconnect(1);
        
                while(!TCPSocket.dead)
                    TCPSocket.Send(bytes, "\xE0"); 
                
                break;
            case UNOFFICIAL:
                TCPSocket.Send('PAGE from player\r\n\r\n%s', bytes);

            case FACEIT:
                while(!TCPSocket.extended)
                    TCPSocket.Send('Valve Automatic Paging Request %s', bytes);
        }
    }
}
