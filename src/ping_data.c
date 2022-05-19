#include "ft_ping.h"

uint8_t Fu8__init_cstc_ping_data(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is already initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == TRUE)
        {
        /**
        * Treat the case when the structure ping data is already initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is not initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint16_t u16_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u16_lcl_cnt                 = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Initialize to not initialized the structure argument of the structure ping data
    */
    ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ = 0;

    /**
    * Initialize the global status of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u8_global_status_ = 0;

    /**
    * Initialize the ip family of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u16_ip_family_ = 0;

    /**
    * Initialize the ip address structure of the structure ping data
    */
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_ipv4_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_ipv4_address_));
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_ipv6_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_ipv6_address_));

    /**
    * Initialize the receve ip address structure of the structure ping data
    */
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_));
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_));

    /**
    * Initialize the string ip address of the structure ping data
    */
    u16_lcl_cnt = 0;
    while(u16_lcl_cnt < INET_V4_V6_ADDRSTRLEN)
        {
        ptr_cstc_pssd_ping_data->u8_ip_address_str_[u16_lcl_cnt] = NIL;

        /**
        * Checking for overflow
        */
        if(u16_lcl_cnt < UINT16_MAX)
            {
            u16_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Initialize the socket of the structure ping data
    */
    ptr_cstc_pssd_ping_data->s32_socket_ = -1;

    /**
    * Initialize the packet sequence of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u16_packet_sequence_ = 0;

    /**
    * Initialize the time value of the structure ping data
    */
    ptr_cstc_pssd_ping_data->estc_rtt_min_               = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_max_               = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_total_             = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_square_total_      = 0;
    ptr_cstc_pssd_ping_data->estc_start_time_            = 0;

    /**
    * Initialize the number of packet transmitted of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_ = 0;

    /**
    * Initialize the number of packet receved of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_packets_receved_ = 0;

    /**
    * Initialize the number of error of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_errors_ = 0;

    /**
    * Setting packet data
    */
    ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_ = 0;
    ptr_cstc_pssd_ping_data->s32_ttl_                     = 0;

    /**
    * Initialize the structure argument of the structure ping data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_argument_init((argument_t *) &(ptr_cstc_pssd_ping_data->sstc_argument_));

    /**
    * Check if function to init the structure argument of the structure ping data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure argument of the structure ping data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure argument of the structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure argument of the structure ping data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure argument of the structure ping data succeeded
        */
        }

    /**
    * Setting the structure ping data to initialized
    */
    ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ = TRUE;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__close_cstc_ping_data(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    int32_t  s32_lcl_return_from_function;
    uint16_t u16_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_function = -1;
    u16_lcl_cnt                  = 0;
    u8_lcl_return_from_function  = RETURN_FAILURE;

    /**
    * Reseting the ip family of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u16_ip_family_ = 0;

    /**
    * Reseting the ip address structure of the structure ping data
    */
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_ipv4_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_ipv4_address_));
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_ipv6_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_ipv6_address_));

    /**
    * Reseting the receve ip address structure of the structure ping data
    */
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_));
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_));

    /**
    * Reseting the string ip address of the structure ping data
    */
    u16_lcl_cnt = 0;
    while(u16_lcl_cnt < INET_V4_V6_ADDRSTRLEN)
        {
        ptr_cstc_pssd_ping_data->u8_ip_address_str_[u16_lcl_cnt] = NIL;

        /**
        * Checking for overflow
        */
        if(u16_lcl_cnt < UINT16_MAX)
            {
            u16_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    /**
    * Check if the socket of the structure ping data is set
    */
    if(ptr_cstc_pssd_ping_data->s32_socket_ >= 0)
        {
        /**
        * Treat the case when the socket of the structure ping data is set
        */

        /**
        * Closing the socket of the structure ping data
        */
        s32_lcl_return_from_function         = -1;
        s32_lcl_return_from_function         = close(ptr_cstc_pssd_ping_data->s32_socket_);
        ptr_cstc_pssd_ping_data->s32_socket_ = -1;

        /**
        * Check if function to close the socket of the structure ping data succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to close the socket of the structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the socket of the structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the socket of the structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the socket of the structure ping data succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the socket of the structure ping data is not set
        */
        }

    /**
    * Reseting the socket of the structure ping data
    */
    ptr_cstc_pssd_ping_data->s32_socket_ = -1;

    /**
    * Reseting the packet sequence of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u16_packet_sequence_ = 0;

    /**
    * Reseting the time value of the structure ping data
    */
    ptr_cstc_pssd_ping_data->estc_rtt_min_               = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_max_               = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_total_             = 0;
    ptr_cstc_pssd_ping_data->estc_rtt_square_total_      = 0;
    ptr_cstc_pssd_ping_data->estc_start_time_            = 0;

    /**
    * Reseting the number of packet transmitted of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_ = 0;

    /**
    * Reseting the number of packet receved of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_packets_receved_ = 0;

    /**
    * Reseting the number of error of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u32_number_errors_ = 0;

    /**
    * Setting packet data
    */
    ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_ = 0;
    ptr_cstc_pssd_ping_data->s32_ttl_                     = 0;

    /**
    * Check if the structure argument is initialized
    */
    if((ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure argument is initialized
        */

        /**
        * Closing the structure argument of the structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_argument_close((argument_t *) &ptr_cstc_pssd_ping_data->sstc_argument_);

        /**
        * Check if function to close the structure argument of the structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure argument of the structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure argument of the structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure argument of the structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure argument of the structure ping data succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the structure argument is not initialized
        */
        }

    /**
    * Reseting the global status of the structure ping data
    */
    ptr_cstc_pssd_ping_data->u8_global_status_ = 0;

    return (RETURN_SUCCESS);
    }

void Fv__display_cstc_ping_data(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    #ifndef DEVELOPEMENT
    return ;
    #endif

    #ifdef DEMO
    return ;
    #endif

    #ifdef PRODUCTION
    return ;
    #endif

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure ping data is not initialized
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    ft_printf("    ***********************************************\n");
    ft_printf("    *              STRUCTURE PING DATA            *\n");
    ft_printf("    ***********************************************\n\n");

    /**
    * Display the ip family of the structure ping data
    */
    switch(ptr_cstc_pssd_ping_data->u16_ip_family_)
        {
        case(AF_INET):
            ft_printf(" IP FAMILY \033[1;93;40mIP V4\033[0m\n");
            break;
        case(AF_INET6):
            ft_printf(" IP FAMILY \033[1;93;40mIP V6\033[0m\n");
            break;
        default:
            ft_printf(" IP FAMILY \033[1;95;40mNOT SET\033[0m\n");
            break;
        }

    /**
    * Display the ip address structure of the structure ping data
    */
    printf("\n IP ADDRESS STRUCTURE:\n\n");

    /**
    * Display the string ip address of the structure ping data
    */
    printf(" IP ADDRESS:         [\033[1;93;40m%s\033[0m]\n\n", ptr_cstc_pssd_ping_data->u8_ip_address_str_);

    /**
    * Check if the socket of the structure ping data is set
    */
    if(ptr_cstc_pssd_ping_data->s32_socket_ >= 0)
        {
        /**
        * Treat the case when the socket of the structure ping data is set
        */

        /**
        * Display the socket of the structure ping data
        */
        printf(" SOCKET: SET         [\033[1;93;40m%d\033[0m]\n\n", ptr_cstc_pssd_ping_data->s32_socket_);
        }
    else
        {
        /**
        * Treat the case when the socket of the structure ping data is not set
        */

        /**
        * Display the socket of the structure ping data
        */
        printf(" SOCKET: NOT SET     [\033[1;95;40m%d\033[0m]\n\n", ptr_cstc_pssd_ping_data->s32_socket_);
        }

    /**
    * Display the packet sequence of the structure ping data
    */
    printf(" PACKET SEQUENCE:    [\033[1;95;40m%u\033[0m]\n\n", ptr_cstc_pssd_ping_data->u16_packet_sequence_);

    /**
    * Display the time value of the structure ping data
    */
    printf(" RTT MIN:            [\033[1;95;40m%lu\033[0m]\n", ptr_cstc_pssd_ping_data->estc_rtt_min_);
    printf(" RTT MAX:            [\033[1;95;40m%lu\033[0m]\n", ptr_cstc_pssd_ping_data->estc_rtt_max_);
    printf(" RTT TOTAL:          [\033[1;95;40m%lu\033[0m]\n", ptr_cstc_pssd_ping_data->estc_rtt_total_);
    printf(" RTT SEQUENCE TOTAL: [\033[1;95;40m%lu\033[0m]\n", ptr_cstc_pssd_ping_data->estc_rtt_square_total_);
    printf(" RTT START TIME:     [\033[1;95;40m%lu\033[0m]\n\n", ptr_cstc_pssd_ping_data->estc_start_time_);

    /**
    * Display the number of packet transmitted of the structure ping data
    */
    printf(" PACKET TRANSMITTED: [\033[1;95;40m%u\033[0m]\n", ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_);

    /**
    * Display the number of packet receved of the structure ping data
    */
    printf(" PACKET RECEVE:      [\033[1;95;40m%u\033[0m]\n", ptr_cstc_pssd_ping_data->u32_number_packets_receved_);

    /**
    * Display the number of error of the structure ping data
    */
    printf(" PACKET ERROR:       [\033[1;95;40m%u\033[0m]\n\n", ptr_cstc_pssd_ping_data->u32_number_errors_);

    /**
    * Display packet data
    */
    printf(" NUMBER OF BYTES RECEVE: [\033[1;95;40m%ld\033[0m]\n\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_);
    printf(" TTL:                    [\033[1;95;40m%u\033[0m]\n\n", ptr_cstc_pssd_ping_data->s32_ttl_);

    /**
    * Check if the structure argument is initialized
    */
    if((ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure argument is initialized
        */

        (void) Fv__structure_argument_display((argument_t *) &ptr_cstc_pssd_ping_data->sstc_argument_);
        }
    else
        {
        /**
        * Treat the case when the structure argument is not initialized
        */

        printf(" STRUCTURE ARGUMENT NOT INITIALIZED\n");
        }

    ft_printf("\n    ***********************************************\n");
    ft_printf("    *            END STRUCTURE PING DATA          *\n");
    ft_printf("    ***********************************************\n");
    }

uint8_t Fu8__get_value_from_ping_argument(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Check if the structure argument in the struture ping data passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument in the struture ping data passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument in the struture ping data passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument in the struture ping data passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument in the struture ping data passed in argument of the function is initialized
        */
        }

    /**
    * Creation of local variable
    */
    int32_t          s32_lcl_return_from_function;
    struct addrinfo  estc_lcl_address_requested;
    struct addrinfo *ptr_estc_lcl_address_receved;
    uint8_t         *ptr_u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    ptr_estc_lcl_address_receved    = NULL;
    ptr_u8_lcl_return_from_function = NULL;
    s32_lcl_return_from_function    = 1;

    ft_memset(&estc_lcl_address_requested, 0, sizeof(struct addrinfo));

    /**
    * Check if the number of destination argument is not one
    */
    if(ptr_cstc_pssd_ping_data->sstc_argument_.u64_number_of_additional_argument_ != 1)
        {
        /**
        * Treat the case when the number of destination argument is not one
        */

        (void) Fv__help();

        /**
        * Setting the flag silent error error
        */
        ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;

        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of destination argument is one
        */
        }

    /**
    * Allow IPv4 or IPv6
    */
    estc_lcl_address_requested.ai_family = AF_UNSPEC;

    /**
    * Getting the address information of the given destination
    */
    s32_lcl_return_from_function = 1;
    s32_lcl_return_from_function = getaddrinfo((char *) ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_additional_argument_str_[0], NULL, &estc_lcl_address_requested, &ptr_estc_lcl_address_receved);

    /**
    * Check if the function to get the address information of the given destination succeeded
    */
    if((s32_lcl_return_from_function != 0) || (ptr_estc_lcl_address_receved == NULL) || ((ptr_estc_lcl_address_receved->ai_family != AF_INET) && (ptr_estc_lcl_address_receved->ai_family != AF_INET6)))
        {
        /**
        * Treat the case when the function to get the address information of the given destination failed
        */

        switch(s32_lcl_return_from_function)
            {
            case(EAI_AGAIN):
                fprintf(stderr, "ft_ping: %s: Temporary failure in name resolution\n", ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_additional_argument_str_[0]);
                ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;
                return (RETURN_FAILURE);
                break;
            case(EAI_NONAME):
                fprintf(stderr, "ft_ping: %s: Name or service not known\n", ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_additional_argument_str_[0]);
                ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;
                return (RETURN_FAILURE);
                break;
            default:
                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in the function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the address information of the given destination failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif
                break;
            }

        /**
        * Return failure to indicate the function to get the address information of the given destination failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the function to get the address information of the given destination succeeded
        */
        }

    /**
    * Getting the ip family
    */
    ptr_cstc_pssd_ping_data->u16_ip_family_ = ptr_estc_lcl_address_receved->ai_family;

    /**
    * Check if the address of the structure ip is not correctly pointing
    */
    if(ptr_estc_lcl_address_receved->ai_addr == NULL)
        {
        /**
        * Treat the case when the address of the structure ip is not correctly pointing
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the address of the structure ip is not correctly pointing\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the address of the structure ip is not correctly pointing
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the address of the structure ip is correctly pointing
        */
        }

    /**
    * Check if the ip family is ip v4
    */
    if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
        {
        /**
        * Treat the case when the ip family is ip v4
        */

        /**
        * Getting the ip v4 address structure of the destination
        */
        ptr_cstc_pssd_ping_data->estc_ipv4_address_ = *((struct sockaddr_in *) ptr_estc_lcl_address_receved->ai_addr);

        /**
        * Getting the ip v4 into a character string
        */
        ptr_u8_lcl_return_from_function = NULL;
        ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET, (void *) &(ptr_cstc_pssd_ping_data->estc_ipv4_address_.sin_addr), (char *) ptr_cstc_pssd_ping_data->u8_ip_address_str_, INET_V4_V6_ADDRSTRLEN);

        /**
        * Check if function to get the ip v4 into a character string succeeded
        */
        if(ptr_u8_lcl_return_from_function == NULL)
            {
            /**
            * Treat the case when the function to get the ip v4 into a character string failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the ip v4 into a character string failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the ip v4 into a character string failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the ip v4 into a character string succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the ip family is ip v6
        */

        /**
        * Getting the ip v6 address structure of the destination
        */
        ptr_cstc_pssd_ping_data->estc_ipv6_address_ = *((struct sockaddr_in6 *) ptr_estc_lcl_address_receved->ai_addr);

        /**
        * Getting the ip v6 into a character string
        */
        ptr_u8_lcl_return_from_function = NULL;
        ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET6, (void *) &(ptr_cstc_pssd_ping_data->estc_ipv6_address_.sin6_addr), (char *) ptr_cstc_pssd_ping_data->u8_ip_address_str_, INET_V4_V6_ADDRSTRLEN);

        /**
        * Check if function to get the ip v6 into a character string succeeded
        */
        if(ptr_u8_lcl_return_from_function == NULL)
            {
            /**
            * Treat the case when the function to get the ip v6 into a character string failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the ip v6 into a character string failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the ip v6 into a character string failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the ip v6 into a character string succeeded
            */
            }
        }

    /**
    * Freeing and setting to NULL the address info structure
    */
    (void) freeaddrinfo(ptr_estc_lcl_address_receved);
    ptr_estc_lcl_address_receved = NULL;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__start_connection(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    int32_t s32_lcl_return_from_function;
    int32_t s32_lcl_socket;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_function = -1;
    s32_lcl_socket               = -1;

    /**
    * Check if the actual protocol is ip v4
    */
    if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
        {
        /**
        * Treat the case when the actual protocol is ip v4
        */

        /**
        * Setting the socket to the destination
        */
        s32_lcl_socket = -1;
        s32_lcl_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
        }
    else
        {
        /**
        * Treat the case when the actual protocol is ip v6
        */

        /**
        * Setting the socket to the destination
        */
        s32_lcl_socket = -1;
        s32_lcl_socket = socket(AF_INET6, SOCK_DGRAM, IPPROTO_ICMPV6);
        }

    /**
    * Check if function to set the socket to the destination succeeded
    */
    if(s32_lcl_socket == -1)
        {
        /**
        * Treat the case when the function to set the socket to the destination failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the socket to the destination failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the socket to the destination failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the socket to the destination succeeded
        */
        }

    /**
    * Setting the option to get the time to live in the receving message
    */
    s32_lcl_return_from_function = -1;
    s32_lcl_return_from_function = setsockopt(s32_lcl_socket, IPPROTO_IP, IP_RECVTTL, (int[1]) {1}, sizeof(int));

    /**
    * Check if function to set the option to get the time to live in the receving message succeeded
    */
    if(s32_lcl_return_from_function != 0)
        {
        /**
        * Treat the case when the function to set the option to get the time to live in the receving message failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the option to get the time to live in the receving message failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the socket to send icmp echo request
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = close(s32_lcl_socket);
        s32_lcl_socket               = -1;

        /**
        * Check if function to close the socket to send icmp echo request succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to close the socket to send icmp echo request failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the socket to send icmp echo request failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the socket to send icmp echo request failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the socket to send icmp echo request succeeded
            */
            }

        /**
        * Return failure to indicate the function to set the option to get the time to live in the receving message failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the option to get the time to live in the receving message succeeded
        */
        }

    /**
    * Check if the actual protocol is ip v6
    */
    if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET6)
        {
        /**
        * Treat the case when the actual protocol is ip v6
        */

        /**
        * Setting the option to get the time to live in the receving message
        */
        s32_lcl_return_from_function = -1;
        s32_lcl_return_from_function = setsockopt(s32_lcl_socket, IPPROTO_IPV6, IPV6_RECVHOPLIMIT, (int[1]) {1}, sizeof(int));

        /**
        * Check if function to set the option to get the time to live in the receving message succeeded
        */
        if(s32_lcl_return_from_function != 0)
            {
            /**
            * Treat the case when the function to set the option to get the time to live in the receving message failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the option to get the time to live in the receving message failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the socket to send icmp echo request
            */
            s32_lcl_return_from_function = RETURN_FAILURE;
            s32_lcl_return_from_function = close(s32_lcl_socket);
            s32_lcl_socket               = -1;

            /**
            * Check if function to close the socket to send icmp echo request succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the socket to send icmp echo request failed
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the socket to send icmp echo request failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the socket to send icmp echo request failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the socket to send icmp echo request succeeded
                */
                }

            /**
            * Return failure to indicate the function to set the option to get the time to live in the receving message failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the option to get the time to live in the receving message succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the actual protocol is ip v4
        */
        }

    /**
    * Setting the socket to the global structure ping data
    */
    ptr_cstc_pssd_ping_data->s32_socket_ = s32_lcl_socket;

    /**
    * Setting the start time to the global structure ping data
    */
    ptr_cstc_pssd_ping_data->estc_start_time_ = get_time();

    return (RETURN_SUCCESS);
    }

void Fv__display_ping_statistic(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure ping data is not initialized
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Check if the structure argument in the struture ping data passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument in the struture ping data passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument in the struture ping data passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure argument in the struture ping data passed in argument of the function is not initialized
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure argument in the struture ping data passed in argument of the function is initialized
        */
        }

    /**
    * Creation of local variable
    */
    suseconds_t estc_lcl_mdev;

    /**
    * Initialization of local variable
    */
    estc_lcl_mdev = 0;

    printf("\n--- %s ping statistics ----\n", ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_additional_argument_str_[0]);
    printf("%u packets transmitted, ", ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_);
    printf("%u received, ", ptr_cstc_pssd_ping_data->u32_number_packets_receved_);
    printf("%u%% packet loss, ", (uint32_t) ((1.0f - ((float) ptr_cstc_pssd_ping_data->u32_number_packets_receved_ / (float) ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_)) * 100.0f));
    printf("time %lums\n", (get_time() - ptr_cstc_pssd_ping_data->estc_start_time_) / 1000);

    if(ptr_cstc_pssd_ping_data->u32_number_packets_receved_ > 0)
        {
        estc_lcl_mdev = ptr_cstc_pssd_ping_data->estc_rtt_total_ / ptr_cstc_pssd_ping_data->u32_number_packets_receved_;
        ptr_cstc_pssd_ping_data->estc_rtt_square_total_ = ptr_cstc_pssd_ping_data->estc_rtt_square_total_ / ptr_cstc_pssd_ping_data->u32_number_packets_receved_;

        estc_lcl_mdev = sqrtl(ptr_cstc_pssd_ping_data->estc_rtt_square_total_ - (estc_lcl_mdev * estc_lcl_mdev));

        printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", ptr_cstc_pssd_ping_data->estc_rtt_min_ / 1000.0f, ptr_cstc_pssd_ping_data->estc_rtt_total_ / (float) ptr_cstc_pssd_ping_data->u32_number_packets_receved_ / 1000.0f, ptr_cstc_pssd_ping_data->estc_rtt_max_ / 1000.0f, estc_lcl_mdev / 1000.0f);
        }
    }

uint8_t Fu8__send_ping(volatile struct cstc_ping_data *ptr_cstc_pssd_ping_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure ping data is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_ping_data == NULL)
        {
        /**
        * Treat the case when the structure ping data is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure ping data is not initialized
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_struct_init_ == FALSE)
        {
        /**
        * Treat the case when the structure ping data is not initialized
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure ping data is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    ssize_t          estc_lcl_number_of_bytes_send;
    struct icmp6hdr *ptr_estc_lcl_icmpv6_header;
    struct icmphdr  *ptr_estc_lcl_icmp_header;
    uint8_t          u8_lcl_packet[ICMP_HDR_SIZE + ICMP_PAYLOAD_SIZE];

    /**
    * Initialization of local variable
    */
    estc_lcl_number_of_bytes_send = -1;
    ptr_estc_lcl_icmp_header      = NULL;
    ptr_estc_lcl_icmpv6_header    = NULL;

    (void) ft_memset(u8_lcl_packet, 0, ICMP_HDR_SIZE + ICMP_PAYLOAD_SIZE);

    ptr_cstc_pssd_ping_data->u16_packet_sequence_++;

    /**
    * Check if the actual protocol is ip v4
    */
    if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
        {
        /**
        * Treat the case when the actual protocol is ip v4
        */

        /**
        * Setting the icmp v4 header to echo request
        */
        ptr_estc_lcl_icmp_header                   = (struct icmphdr *) u8_lcl_packet;

        ptr_estc_lcl_icmp_header->type             = ICMP_ECHO;
        ptr_estc_lcl_icmp_header->code             = 0;
        ptr_estc_lcl_icmp_header->un.echo.id       = htons(42);
        ptr_estc_lcl_icmp_header->un.echo.sequence = htons(ptr_cstc_pssd_ping_data->u16_packet_sequence_);
        }
    else
        {
        /**
        * Treat the case when the actual protocol is ip v6
        */

        /**
        * Setting the icmp v6 header to echo request
        */
        ptr_estc_lcl_icmpv6_header                   = (struct icmp6hdr *) u8_lcl_packet;

        ptr_estc_lcl_icmpv6_header->icmp6_type       = ICMPV6_ECHO_REQUEST;
        ptr_estc_lcl_icmpv6_header->icmp6_code       = 0;
        ptr_estc_lcl_icmpv6_header->icmp6_identifier = htons(42);
        ptr_estc_lcl_icmpv6_header->icmp6_sequence   = htons(ptr_cstc_pssd_ping_data->u16_packet_sequence_);
        }

    (void) memset(u8_lcl_packet + ICMP_HDR_SIZE, 42, ICMP_PAYLOAD_SIZE);

    (void) gettimeofday((void *) (u8_lcl_packet + ICMP_HDR_SIZE + ALIGN_TIMESTAMP), NULL);

    /**
    * Check if the actual protocol is ip v4
    */
    if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
        {
        /**
        * Treat the case when the actual protocol is ip v4
        */

        /**
        * Sending the icmp v4 echo request to the destination
        */
        estc_lcl_number_of_bytes_send = RETURN_FAILURE;
        estc_lcl_number_of_bytes_send = sendto(ptr_cstc_pssd_ping_data->s32_socket_, u8_lcl_packet, sizeof(u8_lcl_packet), 0, (struct sockaddr *) &ptr_cstc_pssd_ping_data->estc_ipv4_address_, sizeof(struct sockaddr_in));

        /**
        * Check if function to send the icmp v4 echo request to the destination succeeded
        */
        if(estc_lcl_number_of_bytes_send < 0)
            {
            /**
            * Treat the case when the function to send the icmp v4 echo request to the destination failed
            */

            switch(errno)
                {
                case(EINVAL):
                    fprintf(stderr, "ft_ping: sendmsg: Invalid argument\n");
                    return (RETURN_SUCCESS);
                    break;
                case(EACCES):
                    fprintf(stderr, "can not ping to breadcast\n");
                    ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;
                    return (RETURN_FAILURE);
                    break;
                default:
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to send the icmp v4 echo request to the destination failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                    #endif
                    break;
                }

            /**
            * Return failure to indicate the function to send the icmp v4 echo request to the destination failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to send the icmp v4 echo request to the destination succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the actual protocol is ip v6
        */

        /**
        * Sending the icmp v6 echo request to the destination
        */
        estc_lcl_number_of_bytes_send = RETURN_FAILURE;
        estc_lcl_number_of_bytes_send = sendto(ptr_cstc_pssd_ping_data->s32_socket_, u8_lcl_packet, sizeof(u8_lcl_packet), 0, (struct sockaddr *) &ptr_cstc_pssd_ping_data->estc_ipv6_address_, sizeof(struct sockaddr_in6));

        /**
        * Check if function to send the icmp v6 echo request to the destination succeeded
        */
        if(estc_lcl_number_of_bytes_send < 0)
            {
            /**
            * Treat the case when the function to send the icmp v6 echo request to the destination failed
            */

            switch(errno)
                {
                case(EINVAL):
                    fprintf(stderr, "ft_ping: sendmsg: Invalid argument\n");
                    return (RETURN_SUCCESS);
                    break;
                case(EACCES):
                    fprintf(stderr, "can not ping to breadcast\n");
                    ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;
                    return (RETURN_FAILURE);
                    break;
                default:
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to send the icmp v6 echo request to the destination failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to send the icmp v6 echo request to the destination failed
                    */
                    return (RETURN_FAILURE);
                    break;
                }
            }
        else
            {
            /**
            * Treat the case when function to send the icmp v6 echo request to the destination succeeded
            */
            }
        }

    /**
    * Checking for overflow
    */
    if(ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_ < UINT32_MAX)
        {
        ptr_cstc_pssd_ping_data->u32_number_packets_transmitted_++;
        }
    else
        {
        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return a failure to indicate the counter variable overflow
        */
        return (RETURN_FAILURE);
        }

    return (RETURN_SUCCESS);
    }
