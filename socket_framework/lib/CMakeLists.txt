#set(lib
#        channel.c
#        event_loop.c
#        poll_dispatcher.c
#        accepter.c
#        tcp_server.c
#        event_loop_thread.c
#        thread_pool.c
#        buffer.c
#        tcp_connection.c
#        )

aux_source_directory(. DIR_LIB_SRCS)

add_library(Network_framework ${DIR_LIB_SRCS})

install(TARGETS Network_framework DESTINATION lib)