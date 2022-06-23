#include "ft_ping.h"

struct cstc_ping_data cstc_glbl_ping_data =
    {
    .u8_global_status_ = 0,
    };

uint16_t ft_bswap_16(uint16_t value)
    {
    return (((__uint16_t) ((((value) >> 8) & 0xff) | (((value) & 0xff) << 8))));
    }

uint16_t ft_htons(uint16_t value)
    {
#if BYTE_ORDER == BIG_ENDIAN
    return (value);
#elif BYTE_ORDER == LITTLE_ENDIAN
    return (ft_bswap_16(value));
#else
# error "What kind of system is this?"
#endif
    }

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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the actual time of the day failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        return (0);
        }
    else
        {
        /**
        * Treat the case when function to get the actual time of the day succeeded
        */
        }

    return ((estc_lcl_time_value.tv_sec * ONE_SECOND_IN_MICROSECOND) + estc_lcl_time_value.tv_usec);
    }

void Fv__help(void)
    {
    ft_fprintf(STDERR_FILENO, "Usage\n");
    ft_fprintf(STDERR_FILENO, "  ft_ping [options] <destination>\n\n");
    ft_fprintf(STDERR_FILENO, "  <destination>      dns name or ip address\n\n");
    ft_fprintf(STDERR_FILENO, "Options:\n");
    ft_fprintf(STDERR_FILENO, "  -h                 print help and exit\n");
    ft_fprintf(STDERR_FILENO, "  -v                 verbose output\n");
    ft_fprintf(STDERR_FILENO, "  -q                 quiet output\n");
    ft_fprintf(STDERR_FILENO, "  -n                 no dns name resolution\n");
    ft_fprintf(STDERR_FILENO, "  -4                 use IPv4\n");
    ft_fprintf(STDERR_FILENO, "  -6                 use IPv6\n");
    ft_fprintf(STDERR_FILENO, "  -f                 flood ping\n");
    ft_fprintf(STDERR_FILENO, "  -D                 Print timestamp (unix time + microseconds as in gettimeofday) before each line\n");
    ft_fprintf(STDERR_FILENO, "  -c <number>        Stop after sending count ECHO_REQUEST packets.\n");
    ft_fprintf(STDERR_FILENO, "  -l <preload>       send <preload> number of packages while waiting replies\n");
    ft_fprintf(STDERR_FILENO, "  -m <mark>          tag the packets going out\n");
    ft_fprintf(STDERR_FILENO, "  -t <ttl>           define time to live\n");
    ft_fprintf(STDERR_FILENO, "  -w <deadline>      reply wait <deadline> in seconds\n");
    ft_fprintf(STDERR_FILENO, "  -p <pattern>       contents of padding byte\n");
    ft_fprintf(STDERR_FILENO, "  -S <size>          use <size> as SO_SNDBUF socket option value\n");
    }

uint8_t Fu8__preload_ping(struct cstc_ping_data *ptr_cstc_pssd_ping_data)
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
    int32_t s32_lcl_cnt;
    int32_t s32_lcl_value;
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_cnt                 = 0;
    s32_lcl_value               = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    s32_lcl_value = ft_atoi((char *) ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PRELOAD]);

    if(s32_lcl_value < 1 || s32_lcl_value > 65536)
        {
        ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 1 <= value <= 65536\n", ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PRELOAD]);

        ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;

        return (RETURN_FAILURE);
        }

    if((s32_lcl_value > PRELOAD_PING_NOT_ROOT_MAX) && (getuid() != ROOT_USER))
        {
        ft_fprintf(STDERR_FILENO, "ft_ping: cannot set preload to value greater than %u: %s\n", PRELOAD_PING_NOT_ROOT_MAX, ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PRELOAD]);

        ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;

        return (RETURN_FAILURE);
        }

    s32_lcl_cnt = 0;
    while(s32_lcl_cnt < s32_lcl_value)
        {
        /**
        * Sending preload ping
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__send_ping(ptr_cstc_pssd_ping_data);

        /**
        * Check if function to send preload ping succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to send preload ping failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to send preload ping failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to send preload ping failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to send preload ping succeeded
            */
            }

        /**
        * Checking for overflow
        */
        if(s32_lcl_cnt < INT32_MAX)
            {
            s32_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            } 
        }

    return (RETURN_SUCCESS);
    }

uint8_t get_hex_char_value(uint8_t u8_pssd_hex_char)
    {
    if(u8_pssd_hex_char >= '0' && u8_pssd_hex_char <= '9')
        return(u8_pssd_hex_char - '0');
    if(u8_pssd_hex_char >= 'a' && u8_pssd_hex_char <= 'f')
        return(u8_pssd_hex_char - 'a' + 10);
    if(u8_pssd_hex_char >= 'A' && u8_pssd_hex_char <= 'F')
        return(u8_pssd_hex_char - 'A' + 10);
    return(0);
    }

uint8_t Fu8__getting_pattern(struct cstc_ping_data *ptr_cstc_pssd_ping_data)
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure ping data is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
    * Check if the structure argument is not set
    */
    if((ptr_cstc_pssd_ping_data->sstc_argument_.u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument is not set
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not set\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not set
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is set
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_cnt;
    uint8_t u8_lcl_value_first_hex_char;
    uint8_t u8_lcl_value_second_hex_char;
    uint8_t u8_lcl_pattern_str_size;

    /**
    * Initialization of local variable
    */
    u8_lcl_cnt                   = 0;
    u8_lcl_pattern_str_size      = 0;
    u8_lcl_value_first_hex_char  = 0;
    u8_lcl_value_second_hex_char = 0;

    /**
    * Check if the pattern option is not set
    */
    if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_argument_options_[PATTERN] == FALSE || (ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN] == NULL))
        {
        /**
        * Treat the case when the pattern option is not set
        */

        ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_argument_options_[PATTERN] = FALSE;
        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the pattern option is set
        */
        }

    /**
    * Getting the pattern string size
    */
    u8_lcl_pattern_str_size = 0;
    while((ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] != NIL) && (u8_lcl_pattern_str_size < (2 * PATTERN_MAX_SIZE)))
        {
        /**
        * Check if the actual character is not an hexadecimal character
        */
        if((ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] < '0' || ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] > '9') && (ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] < 'a' || ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] > 'f') && (ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] < 'A' || ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size] > 'F'))
            {
            /**
            * Treat the case when the actual character is not an hexadecimal character
            */

            ptr_cstc_pssd_ping_data->u8_global_status_silent_error_ = TRUE;

            ft_fprintf(STDERR_FILENO, "ft_ping: patterns must be specified as hex digits: %c\n", ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_pattern_str_size]);

            /**
            * Return failure to indicate the actual character is not an hexadecimal character
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the actual character is an hexadecimal character
            */
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_pattern_str_size < UINT8_MAX)
            {
            u8_lcl_pattern_str_size++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            }
        }

    ft_printf("PATTERN: 0x");
    u8_lcl_cnt = 0;
    while(((u8_lcl_cnt * 2) < u8_lcl_pattern_str_size) && (u8_lcl_cnt < PATTERN_MAX_SIZE))
        {
        u8_lcl_value_first_hex_char  = 0;
        u8_lcl_value_second_hex_char = 0;

        if(((u8_lcl_cnt * 2) + 1) < u8_lcl_pattern_str_size)
            {
            u8_lcl_value_first_hex_char  = get_hex_char_value(ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_cnt * 2]);
            u8_lcl_value_second_hex_char = get_hex_char_value(ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][(u8_lcl_cnt * 2) + 1]);

            ptr_cstc_pssd_ping_data->u8_pattern_[u8_lcl_cnt] = (u8_lcl_value_first_hex_char << 4) | u8_lcl_value_second_hex_char;
            }
        else
            {
            ptr_cstc_pssd_ping_data->u8_pattern_[u8_lcl_cnt] = get_hex_char_value(ptr_cstc_pssd_ping_data->sstc_argument_.dbl_ptr_u8_argument_option_value_str_[PATTERN][u8_lcl_cnt * 2]);
            }

        ft_printf("%02x", ptr_cstc_pssd_ping_data->u8_pattern_[u8_lcl_cnt]);

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */
            return (RETURN_FAILURE);
            } 
        }

    ft_printf("\n");

    ptr_cstc_pssd_ping_data->u8_pattern_size_ = u8_lcl_cnt;

    return (RETURN_SUCCESS);
    }

int main(int argc, char **argv)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    int32_t      s32_lcl_max_echo_packet;
    int32_t      s32_lcl_return_from_function;
    int32_t      s32_lcl_ttl;
    suseconds_t  estc_lcl_actual_time;
    suseconds_t  estc_lcl_dead_line;
    suseconds_t  estc_lcl_last_ping_time;
    suseconds_t  estc_lcl_start_time;
    suseconds_t  estc_lcl_wait_time;
    uint8_t      u8_lcl_return_from_function;
    uint8_t      u8_lcl_return_status;
    void        *ptr_vd_lcl_return_from_signal;

    /**
    * Initialization of local variable
    */
    estc_lcl_actual_time          = 0;
    estc_lcl_dead_line            = 0;
    estc_lcl_last_ping_time       = 0;
    estc_lcl_start_time           = 0;
    estc_lcl_wait_time            = 0;
    ptr_vd_lcl_return_from_signal = SIG_ERR;
    s32_lcl_max_echo_packet       = 0;
    s32_lcl_return_from_function  = 0;
    s32_lcl_ttl                   = 0;
    u8_lcl_return_from_function   = RETURN_FAILURE;
    u8_lcl_return_status          = RETURN_SUCCESS;

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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the exit signal handler failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load information from the argument to the structure argument in the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    /**
    * Getting the pattern from the argument
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__getting_pattern(&cstc_glbl_ping_data);

    /**
    * Check if function to get the pattern from the argument succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get the pattern from the argument failed
        */

        if(cstc_glbl_ping_data.u8_global_status_silent_error_ == FALSE)
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the pattern from the argument failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        * Return failure to indicate the function to get the pattern from the argument failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to get the pattern from the argument succeeded
        */
        }

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[SNDBUF] != FALSE)
        {
        cstc_glbl_ping_data.s32_send_buffer_size_ = ft_atoi((char *) cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[SNDBUF]);

        if(cstc_glbl_ping_data.s32_send_buffer_size_ == 0)
            {
            ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 1 <= value <= 2147483647\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[SNDBUF]);

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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the value of the arguments in the structure argument in the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[TTL] != FALSE)
        {
        s32_lcl_ttl = ft_atoi((char *) cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[TTL]);

        if(s32_lcl_ttl < 1 || s32_lcl_ttl > 255)
            {
            ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 0 < value <= 255\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[TTL]);

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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

        cstc_glbl_ping_data.s32_echo_tll_ = (uint8_t) s32_lcl_ttl;
        }

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[COUNT_ECHO] != FALSE)
        {
        s32_lcl_max_echo_packet = ft_atoi((char *) cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[COUNT_ECHO]);

        if(s32_lcl_max_echo_packet < 1 || s32_lcl_max_echo_packet == INT32_MAX)
            {
            ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 1 <= value < %d\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[COUNT_ECHO], INT32_MAX);

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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

        cstc_glbl_ping_data.u32_max_number_packets_ = s32_lcl_max_echo_packet;
        }

    if(cstc_glbl_ping_data.u16_ip_family_ == AF_INET)
        {
        ft_printf("PING %s (%s) %u(%u) bytes of data.\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_additional_argument_str_[0], cstc_glbl_ping_data.u8_ip_address_str_, ICMP_PAYLOAD_SIZE, PACKET_SIZE);
        }
    else
        {
        ft_printf("PING %s(%s) %u data bytes\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_additional_argument_str_[0], cstc_glbl_ping_data.u8_ip_address_str_, ICMP_PAYLOAD_SIZE);
        }

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[MARK] != FALSE)
        {
        cstc_glbl_ping_data.s32_mark_ = ft_atoi((char *) cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[MARK]);

        if((cstc_glbl_ping_data.s32_mark_ < 0) || (cstc_glbl_ping_data.s32_mark_ > 2147483647))
            {
            ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 0 <= value <= 2147483647\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[MARK]);

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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to start the connection to the destination failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    estc_lcl_last_ping_time = 0;

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[PRELOAD] != FALSE)
        {
        /**
        * Preloading the ping
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__preload_ping(&cstc_glbl_ping_data);

        /**
        * Check if function to preload the ping succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to preload the ping failed
            */

            if(cstc_glbl_ping_data.u8_global_status_silent_error_ == FALSE)
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to preload the ping failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            * Return failure to indicate the function to preload the ping failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to preload the ping succeeded
            */
            }

        estc_lcl_last_ping_time = get_time();
        }

    if((getuid() != ROOT_USER) && (cstc_glbl_ping_data.sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE))
        {
        ft_fprintf(STDERR_FILENO, "ft_ping: cannot flood; minimal interval allowed for user is 200ms\n");

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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    if(cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[DEADLINE] != FALSE)
        {
        s32_lcl_return_from_function = ft_atoi((char *) cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[DEADLINE]);

        if(s32_lcl_return_from_function < 0)
            {
            ft_fprintf(STDERR_FILENO, "ft_ping: invalid argument: '%s': out of range: 0 <= value <= 2147483647\n", cstc_glbl_ping_data.sstc_argument_.dbl_ptr_u8_argument_option_value_str_[DEADLINE]);

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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

        estc_lcl_dead_line = s32_lcl_return_from_function * ONE_SECOND_IN_MICROSECOND;
        }

    estc_lcl_start_time = get_time();
    estc_lcl_actual_time = 0;
    while(((cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[COUNT_ECHO] == FALSE) || ((cstc_glbl_ping_data.u32_number_packets_receved_ + cstc_glbl_ping_data.u32_number_errors_) < cstc_glbl_ping_data.u32_max_number_packets_)) && ((cstc_glbl_ping_data.sstc_argument_.ptr_u8_argument_options_[DEADLINE] == FALSE) || (estc_lcl_dead_line == 0) || (get_time() < (estc_lcl_start_time + estc_lcl_dead_line))))
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
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to send echo request to the destination failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to receve icmp echo reply from destinamtion failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    (void) Fv__display_ping_statistic(&cstc_glbl_ping_data);

    if(cstc_glbl_ping_data.u32_number_errors_ > 0)
        {
        u8_lcl_return_status = RETURN_FAILURE;
        }
    else
        {
        u8_lcl_return_status = RETURN_SUCCESS;
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
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the global structure ping data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
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

    return (u8_lcl_return_status);
    }
