#include "ft_ping.h"

void Fv__signal_handler_exit(__attribute__((unused)) int signal)
    {
    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Check if the global structure ping data is initialized
    */
    if(cstc_glbl_ping_data.u8_global_status_struct_init_ == TRUE)
        {
        /**
        * Treat the case when the global structure ping data is initialized
        */

        (void) Fv__display_ping_statistic(&cstc_glbl_ping_data);

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
            * Exit failure to indicate the function to close the global structure ping data failed
            */
            exit(EXIT_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the global structure ping data succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the global structure ping data is not initialized
        */
        }

    exit(EXIT_SUCCESS);
    }

void Fv__signal_handler_alarm(__attribute__((unused)) int signal)
    {
    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Check if the global structure ping data is initialized
    */
    if(cstc_glbl_ping_data.u8_global_status_struct_init_ == TRUE)
        {
        /**
        * Treat the case when the global structure ping data is initialized
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
            * Return to indicate the function to send echo request to the destination failed
            */
            return;
            }
        else
            {
            /**
            * Treat the case when function to send echo request to the destination succeeded
            */
            }

        (void) alarm(FT_PING_NUMBER_OF_SECONDS_BETWEEN_PING);
        }
    else
        {
        /**
        * Treat the case when the global structure ping data is not initialized
        */
        }
    }
