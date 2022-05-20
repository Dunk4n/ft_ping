#include "ft_ping.h"

volatile struct cstc_ping_data cstc_glbl_ping_data =
    {
    .u8_global_status_ = 0,
    };

suseconds_t get_time(void)
    {
    /**
    * Creation of local variable
    */
    int32_t        s32_lcl_return_from_function;
    struct timeval estc_lcl_time_value;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_function = -1;

    /**
    * Getting the actual time of the day
    */
    s32_lcl_return_from_function = RETURN_FAILURE;
    s32_lcl_return_from_function = gettimeofday(&estc_lcl_time_value, NULL);

    /**
    * Check if function to get the actual time of the day succeeded
    */
    if(s32_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get the actual time of the day failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the actual time of the day failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        return (0);
        }
    else
        {
        /**
        * Treat the case when function to get the actual time of the day succeeded
        */
        }

    return ((estc_lcl_time_value.tv_sec * 1000000) + estc_lcl_time_value.tv_usec);
    }

void Fv__help(void)
    {
    ft_fprintf(STDERR_FILENO, "Usage\n");
    ft_fprintf(STDERR_FILENO, "  ft_ping [options] <destination>\n\n");
    ft_fprintf(STDERR_FILENO, "Options:\n");
    ft_fprintf(STDERR_FILENO, "  <destination>      dns name or ip address\n");
    ft_fprintf(STDERR_FILENO, "  -f                 flood ping\n");
    ft_fprintf(STDERR_FILENO, "  -h                 print help and exit\n");
    ft_fprintf(STDERR_FILENO, "  -I <interface>     either interface name or address\n");
    ft_fprintf(STDERR_FILENO, "  -l <preload>       send <preload> number of packages while waiting replies\n");
    ft_fprintf(STDERR_FILENO, "  -m <mark>          tag the packets going out\n");
    ft_fprintf(STDERR_FILENO, "  -M <pmtud opt>     define mtu discovery, can be one of <do|dont|want>\n");
    ft_fprintf(STDERR_FILENO, "  -n                 no dns name resolution\n");
    ft_fprintf(STDERR_FILENO, "  -p <pattern>       contents of padding byte\n");
    ft_fprintf(STDERR_FILENO, "  -q                 quiet output\n");
    ft_fprintf(STDERR_FILENO, "  -Q <tclass>        use quality of service <tclass> bits\n");
    ft_fprintf(STDERR_FILENO, "  -S <size>          use <size> as SO_SNDBUF socket option value\n");
    ft_fprintf(STDERR_FILENO, "  -t <ttl>           define time to live\n");
    ft_fprintf(STDERR_FILENO, "  -v                 verbose output\n");
    ft_fprintf(STDERR_FILENO, "  -w <deadline>      reply wait <deadline> in seconds\n");
    ft_fprintf(STDERR_FILENO, "  -W <timeout>       time to wait for response\n");
    ft_fprintf(STDERR_FILENO, "  -4                 use IPv4\n");
    ft_fprintf(STDERR_FILENO, "  -6                 use IPv6\n");
    }

int main(int argc, char **argv)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    suseconds_t  estc_lcl_actual_time;
    suseconds_t  estc_lcl_last_ping_time;
    suseconds_t  estc_lcl_wait_time;
    uint8_t      u8_lcl_return_from_function;
    void        *ptr_vd_lcl_return_from_signal;

    /**
    * Initialization of local variable
    */
    estc_lcl_actual_time          = 0;
    estc_lcl_last_ping_time       = 0;
    estc_lcl_wait_time            = 0;
    ptr_vd_lcl_return_from_signal = SIG_ERR;
    u8_lcl_return_from_function   = RETURN_FAILURE;

    /**
    * Setting the exit signal handler
    */
    ptr_vd_lcl_return_from_signal = SIG_ERR;
    ptr_vd_lcl_return_from_signal = signal(SIGINT, Fv__signal_handler_exit);

    /**
    * Check if function to set the exit signal handler succeeded
    */
    if(ptr_vd_lcl_return_from_signal == SIG_ERR)
        {
        /**
        * Treat the case when the function to set the exit signal handler failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the exit signal handler failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the exit signal handler failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the exit signal handler succeeded
        */
        }

    /**
    * Initialize the global structure ping data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__init_cstc_ping_data(&cstc_glbl_ping_data);

    /**
    * Check if function to init the global structure ping data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the global structure ping data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the global structure ping data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the global structure ping data succeeded
        */
        }

    /**
    * Loading information from the argument to the structure argument in the global structure ping data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__load_data_from_argument((argument_t *) &(cstc_glbl_ping_data.sstc_argument_), argc, (uint8_t **) argv);

    /**
    * Check if function to load information from the argument to the structure argument in the global structure ping data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to load information from the argument to the structure argument in the global structure ping data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load information from the argument to the structure argument in the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        /**
        * Return failure to indicate the function to load information from the argument to the structure argument in the global structure ping data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to load information from the argument to the structure argument in the global structure ping data succeeded
        */
        }

    /**
    * Check if argument error
    */
    if((cstc_glbl_ping_data.sstc_argument_.u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when argument error
        */

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when no argument error
        */
        }

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[HELP] != FALSE)
        {
        (void) Fv__help();

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        return (RETURN_SUCCESS);
        }

    if((cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[USE_IPV4] != FALSE) && (cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[USE_IPV6] != FALSE))
        {
        ft_fprintf(STDERR_FILENO, "ft_ping: only one -4 or -6 option may be specified\n");

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        return (RETURN_FAILURE);
        }

    /**
    * Getting the value of the arguments in the structure argument in the global structure ping data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__get_value_from_ping_argument(&cstc_glbl_ping_data);

    /**
    * Check if function to get the value of the arguments in the structure argument in the global structure ping data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get the value of the arguments in the structure argument in the global structure ping data failed
        */

        if(cstc_glbl_ping_data.u8_global_status_silent_error_ == FALSE)
            {
            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the value of the arguments in the structure argument in the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif
            }

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        /**
        * Return failure to indicate the function to get the value of the arguments in the structure argument in the global structure ping data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to get the value of the arguments in the structure argument in the global structure ping data succeeded
        */
        }

    /**
    * Starting the connection to the destination
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__start_connection(&cstc_glbl_ping_data);

    /**
    * Check if function to start the connection to the destination succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to start the connection to the destination failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to start the connection to the destination failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        /**
        * Return failure to indicate the function to start the connection to the destination failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to start the connection to the destination succeeded
        */
        }

    /**
    * Setting the alarm signal handler
    */
    ptr_vd_lcl_return_from_signal = SIG_ERR;
    ptr_vd_lcl_return_from_signal = signal(SIGALRM, Fv__signal_handler_alarm);

    /**
    * Check if function to set the alarm signal handler succeeded
    */
    if(ptr_vd_lcl_return_from_signal == SIG_ERR)
        {
        /**
        * Treat the case when the function to set the alarm signal handler failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the alarm signal handler failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the alarm signal handler failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the alarm signal handler succeeded
        */
        }

    if(cstc_glbl_ping_data.u16_ip_family_ == AF_INET)
        {
        printf("PING %s (%s) %u(%u) bytes of data.\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_additional_argument_str_[0], cstc_glbl_ping_data.u8_ip_address_str_, ICMP_PAYLOAD_SIZE, PACKET_SIZE);
        }
    else
        {
        printf("PING %s(%s) %u data bytes\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_additional_argument_str_[0], cstc_glbl_ping_data.u8_ip_address_str_, ICMP_PAYLOAD_SIZE);
        }

    if((getuid() != ROOT_USER) && (cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE))
        {
        fprintf(stderr, "ft_ping: cannot flood; minimal interval allowed for user is 200ms\n");

        /**
        * Closing the global structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

        /**
        * Check if function to close the global structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the global structure ping data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the global structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }

        /**
        * Return failure to indicate the function to send echo request to the destination failed
        */
        return (RETURN_FAILURE);
        }

    /**
    * Check if the flood option is set
    */
    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE)
        {
        /**
        * Treat the case when the flood option is set
        */

        estc_lcl_wait_time = FLOOD_WAIT;
        }
    else
        {
        /**
        * Treat the case when the flood option is not set
        */

        estc_lcl_wait_time = ONE_SECOND_IN_MICROSECOND;
        }

    estc_lcl_actual_time    = 0;
    estc_lcl_last_ping_time = 0;
    while(TRUE)
        {
        /**
        * Getting the actual time
        */
        estc_lcl_actual_time = get_time();

        /**
        * Check if the time between two pings has passed
        */
        if(estc_lcl_actual_time >= (estc_lcl_last_ping_time + estc_lcl_wait_time))
            {
            /**
            * Treat the case when the time between two pings has passed
            */

            /**
            * Sending echo request to the destination
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__send_ping(&cstc_glbl_ping_data);

            /**
            * Check if function to send echo request to the destination succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to send echo request to the destination failed
                */

                if(cstc_glbl_ping_data.u8_global_status_silent_error_ == FALSE)
                    {
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to send echo request to the destination failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                    #endif
                    }

                /**
                * Closing the global structure ping data
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

                /**
                * Check if function to close the global structure ping data succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the global structure ping data failed
                    */

                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the global structure ping data failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the global structure ping data succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to send echo request to the destination failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to send echo request to the destination succeeded
                */
                }

            /**
            * Getting the new last ping time
            */
            estc_lcl_last_ping_time = get_time();
            }
        else
            {
            /**
            * Treat the case when the time between two pings has not passed
            */
            }

        /**
        * Receving icmp echo reply from destinamtion
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__receve_pong(&cstc_glbl_ping_data);

        /**
        * Check if function to receve icmp echo reply from destinamtion succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to receve icmp echo reply from destinamtion failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to receve icmp echo reply from destinamtion failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the global structure ping data
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

            /**
            * Check if function to close the global structure ping data succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the global structure ping data failed
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the global structure ping data failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the global structure ping data succeeded
                */
                }

            /**
            * Return failure to indicate the function to receve icmp echo reply from destinamtion failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to receve icmp echo reply from destinamtion succeeded
            */
            }
        }

    /**
    * Closing the global structure ping data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__close_cstc_ping_data(&cstc_glbl_ping_data);

    /**
    * Check if function to close the global structure ping data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the global structure ping data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the global structure ping data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the global structure ping data succeeded
        */
        }

    return (RETURN_SUCCESS);
    }
