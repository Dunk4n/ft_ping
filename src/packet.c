#include "ft_ping.h"

static uint16_t Fu16__reverse_endianness(uint16_t u16_pssd_value)
    {
    return((uint16_t) (((uint8_t *) &u16_pssd_value)[1]) | ((uint16_t) (((uint8_t *) &u16_pssd_value)[0]) << 8));
    }

//static uint32_t Fu32__reverse_endianness(uint32_t u32_pssd_value)
//    {
//    return((uint32_t) (((uint8_t *) &u32_pssd_value)[3]) | (((uint32_t) (((uint8_t *) &u32_pssd_value)[2])) << 8) | (((uint32_t) (((uint8_t *) &u32_pssd_value)[1])) << 16 | (((uint32_t) (((uint8_t *) &u32_pssd_value)[0])) << 24)));
//    }

void Fv__display_ipv4_icmp_packet(struct sockaddr_in *ptr_estc_pssd_ipv4_address, ssize_t estc_pssd_packet_number_of_bytes, int32_t s32_pssd_ttl, uint8_t *ptr_u8_pssd_packet)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the ipv4 address is correctly pointing passed as an argument of the function
    */
    if(ptr_estc_pssd_ipv4_address == NULL)
        {
        /**
        * Treat the case when the ipv4 address is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the ipv4 address is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the ipv4 address is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the ipv4 address is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the packet is not an ipv4 packet
    */
    if(ptr_estc_pssd_ipv4_address->sin_family != AF_INET)
        {
        /**
        * Treat the case when the packet is not an ipv4 packet
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not an ipv4 packet\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the packet is not an ipv4 packet
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the packet is an ipv4 packet
        */
        }

    /**
    * Creation of local variable
    */
    struct icmphdr *ptr_estc_lcl_icmp_header;
    uint8_t         u8_lcl_sender_address_str[INET_V4_V6_ADDRSTRLEN];
    uint8_t        *ptr_u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    ptr_estc_lcl_icmp_header        = NULL;
    ptr_u8_lcl_return_from_function = NULL;

    (void) ft_memset(u8_lcl_sender_address_str, 0, INET_V4_V6_ADDRSTRLEN);

    /**
    * Getting data from packet
    */
    ptr_estc_lcl_icmp_header = (void *) ptr_u8_pssd_packet;

    /**
    * Getting the sender address in ascii form
    */
    ptr_u8_lcl_return_from_function = NULL;
    ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET, (void *) &(ptr_estc_pssd_ipv4_address->sin_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

    /**
    * Check if function to get the sender address in ascii form succeeded
    */
    if(ptr_u8_lcl_return_from_function == NULL)
        {
        /**
        * Treat the case when the function to get the sender address in ascii form failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the function to get the sender address in ascii form failed
        */
        return;
        }
    else
        {
        /**
        * Treat the case when function to get the sender address in ascii form succeeded
        */
        }

    ft_printf("\n==========  PACKET  ==========\n");
    ft_printf("IPV4  %s\n", u8_lcl_sender_address_str);
    ft_printf("      TTL: %d | SIZE: %ld\n\n", s32_pssd_ttl, estc_pssd_packet_number_of_bytes);

    ft_printf("ICMP  type: %u | code: %u\n", ptr_estc_lcl_icmp_header->type, ptr_estc_lcl_icmp_header->code);
    ft_printf("      ckecksum: %02x%02x\n", ((uint8_t *) &ptr_estc_lcl_icmp_header->checksum)[0], ((uint8_t *) &ptr_estc_lcl_icmp_header->checksum)[1]);
    ft_printf("      id: %u   | sequence: %u\n", Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.id), Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence));
    ft_printf("==============================\n\n");

    return;
    }

void Fv__display_ipv6_icmp_packet(struct sockaddr_in6 *ptr_estc_pssd_ipv6_address, ssize_t estc_pssd_packet_number_of_bytes, int32_t s32_pssd_ttl, uint8_t *ptr_u8_pssd_packet)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the ipv6 address is correctly pointing passed as an argument of the function
    */
    if(ptr_estc_pssd_ipv6_address == NULL)
        {
        /**
        * Treat the case when the ipv6 address is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the ipv6 address is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the ipv6 address is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the ipv6 address is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the packet is not an ipv6 packet
    */
    if(ptr_estc_pssd_ipv6_address->sin6_family != AF_INET6)
        {
        /**
        * Treat the case when the packet is not an ipv6 packet
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not an ipv6 packet\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the packet is not an ipv6 packet
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the packet is an ipv6 packet
        */
        }

    /**
    * Creation of local variable
    */
    struct icmphdr *ptr_estc_lcl_icmp_header;
    uint8_t         u8_lcl_sender_address_str[INET_V4_V6_ADDRSTRLEN];
    uint8_t        *ptr_u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    ptr_estc_lcl_icmp_header        = NULL;
    ptr_u8_lcl_return_from_function = NULL;

    (void) ft_memset(u8_lcl_sender_address_str, 0, INET_V4_V6_ADDRSTRLEN);

    /**
    * Getting data from packet
    */
    ptr_estc_lcl_icmp_header = (void *) ptr_u8_pssd_packet;

    /**
    * Getting the sender address in ascii form
    */
    ptr_u8_lcl_return_from_function = NULL;
    ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET6, (void *) &(ptr_estc_pssd_ipv6_address->sin6_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

    /**
    * Check if function to get the sender address in ascii form succeeded
    */
    if(ptr_u8_lcl_return_from_function == NULL)
        {
        /**
        * Treat the case when the function to get the sender address in ascii form failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the function to get the sender address in ascii form failed
        */
        return;
        }
    else
        {
        /**
        * Treat the case when function to get the sender address in ascii form succeeded
        */
        }

    ft_printf("\n==========  PACKET  ==========\n");
    ft_printf("IPV6  %s\n", u8_lcl_sender_address_str);
    ft_printf("      TTL: %d | SIZE: %ld\n\n", s32_pssd_ttl, estc_pssd_packet_number_of_bytes);

    ft_printf("ICMP  type: %u | code: %u\n", ptr_estc_lcl_icmp_header->type, ptr_estc_lcl_icmp_header->code);
    ft_printf("      ckecksum: %02x%02x\n", ((uint8_t *) &ptr_estc_lcl_icmp_header->checksum)[0], ((uint8_t *) &ptr_estc_lcl_icmp_header->checksum)[1]);
    ft_printf("      id: %u   | sequence: %u\n", Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.id), Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence));
    ft_printf("==============================\n\n");

    return;
    }

void Fv__display_receved_packet(struct cstc_ping_data *ptr_cstc_pssd_ping_data, uint8_t *ptr_u8_pssd_packet)
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
        return;
        }
    else
        {
        /**
        * Treat the case when the structure ping data is initialized as expected
        */
        }

    /**
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the receve packet is an ipv4 packet
    */
    if(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_.sin_family == AF_INET)
        {
        /**
        * Treat the case when the receve packet is an ipv4 packet
        */

        (void) Fv__display_ipv4_icmp_packet((struct sockaddr_in *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_), ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, ptr_cstc_pssd_ping_data->s32_ttl_, ptr_u8_pssd_packet);
        }
    else
        {
        /**
        * Treat the case when the receve packet is an ipv6 packet
        */

        (void) Fv__display_ipv6_icmp_packet((struct sockaddr_in6 *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_), ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, ptr_cstc_pssd_ping_data->s32_ttl_, ptr_u8_pssd_packet);
        }

    return;
    }

uint8_t Fu8__getting_packet(struct cstc_ping_data *ptr_cstc_pssd_ping_data, uint8_t *ptr_u8_pssd_packet)
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
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    ssize_t                   estc_lcl_number_of_bytes_receve;
    struct cmsghdr           *ptr_estc_lcl_cmsg;
    struct iovec              estc_lcl_io_vector;
    struct msghdr             estc_lcl_message;
    struct sock_extended_err *ptr_estc_lcl_packet_error;
    struct sockaddr          *ptr_estc_lcl_error_return_address;
    struct sockaddr_in6       estc_lcl_ipv6_address;
    uint8_t                   u8_lcl_control_buffer[CMSG_SPACE(sizeof(uint8_t)) + CMSG_SPACE(sizeof(struct sock_extended_err)) + CMSG_SPACE(sizeof(struct sockaddr_in6))];
    uint8_t                  *ptr_u8_lcl_ttl;

    /**
    * Initialization of local variable
    */
    estc_lcl_number_of_bytes_receve   = -1;
    ptr_estc_lcl_cmsg                 = NULL;
    ptr_estc_lcl_error_return_address = NULL;
    ptr_estc_lcl_packet_error         = NULL;
    ptr_u8_lcl_ttl                    = NULL;

    (void) ft_memset(&estc_lcl_message, 0, sizeof(estc_lcl_message));
    (void) ft_memset(&estc_lcl_io_vector, 0, sizeof(estc_lcl_io_vector));
    (void) ft_memset(u8_lcl_control_buffer, 0, sizeof(u8_lcl_control_buffer));
    (void) ft_memset(ptr_u8_pssd_packet, 0, PACKET_SIZE);

    (void) ft_memset(&estc_lcl_ipv6_address, 0, sizeof(estc_lcl_ipv6_address));

    /**
    * Setting message data
    */
    estc_lcl_io_vector.iov_base     = ptr_u8_pssd_packet;
    estc_lcl_io_vector.iov_len      = PACKET_SIZE;

    estc_lcl_message.msg_name       = (void *) &estc_lcl_ipv6_address;
    estc_lcl_message.msg_namelen    = sizeof(estc_lcl_ipv6_address);

    estc_lcl_message.msg_iov        = &estc_lcl_io_vector;
    estc_lcl_message.msg_iovlen     = 1;
    estc_lcl_message.msg_control    = u8_lcl_control_buffer;
    estc_lcl_message.msg_controllen = sizeof(u8_lcl_control_buffer);
    estc_lcl_message.msg_flags      = 0;

    /**
    * Setting packet error data not set
    */
    ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ = FALSE;

    /**
    * Receving the pong message
    */
    estc_lcl_number_of_bytes_receve = -1;
    estc_lcl_number_of_bytes_receve = recvmsg(ptr_cstc_pssd_ping_data->s32_socket_, &estc_lcl_message, MSG_DONTWAIT);

    /**
    * Check if function to receve the pong message succeeded
    */
    if(estc_lcl_number_of_bytes_receve < 0)
        {
        /**
        * Treat the case when the function to receve the pong message failed
        */

        if((errno == EAGAIN) || (errno == EWOULDBLOCK))
            {
            return (RETURN_NOT_FAILURE_BUT_NOT_SUCCESS);
            }

        /**
        * Receving the pong error message
        */
        estc_lcl_number_of_bytes_receve = -1;
        estc_lcl_number_of_bytes_receve = recvmsg(ptr_cstc_pssd_ping_data->s32_socket_, &estc_lcl_message, MSG_DONTWAIT | MSG_ERRQUEUE);

        /**
        * Check if function to receve the pong error message succeeded
        */
        if(estc_lcl_number_of_bytes_receve < 0)
            {
            /**
            * Treat the case when the function to receve the pong error message failed
            */

            if((errno == EAGAIN) || (errno == EWOULDBLOCK))
                {
                return (RETURN_NOT_FAILURE_BUT_NOT_SUCCESS);
                }

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to receve the pong error message failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to receve the pong error message failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to receve the pong error message succeeded
            */
            }

        /**
        * Searching for error
        */
        ptr_estc_lcl_cmsg = CMSG_FIRSTHDR(&estc_lcl_message);
        while(ptr_estc_lcl_cmsg != NULL)
            {
            if(((ptr_estc_lcl_cmsg->cmsg_level == IPPROTO_IP) && (ptr_estc_lcl_cmsg->cmsg_type == IP_RECVERR)) || ((ptr_estc_lcl_cmsg->cmsg_level == IPPROTO_IPV6) && (ptr_estc_lcl_cmsg->cmsg_type == IPV6_RECVERR)))
                {
                ptr_estc_lcl_packet_error = NULL;
                ptr_estc_lcl_packet_error = (struct sock_extended_err *) CMSG_DATA(ptr_estc_lcl_cmsg);

                if((ptr_estc_lcl_packet_error != NULL) && ((ptr_estc_lcl_packet_error->ee_origin == SO_EE_ORIGIN_ICMP) || (ptr_estc_lcl_packet_error->ee_origin == SO_EE_ORIGIN_ICMP6)))
                    {
                    ptr_cstc_pssd_ping_data->estc_error_packet_data_ = *ptr_estc_lcl_packet_error;

                    ptr_estc_lcl_error_return_address = SO_EE_OFFENDER(ptr_estc_lcl_packet_error);

                    if(ptr_estc_lcl_error_return_address->sa_family == AF_INET)
                        {
                        ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_ = *((struct sockaddr_in *) ptr_estc_lcl_error_return_address);
                        }
                    else if(ptr_estc_lcl_error_return_address->sa_family == AF_INET6)
                        {
                        ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_ = *((struct sockaddr_in6 *) ptr_estc_lcl_error_return_address);
                        }
                    else
                        {
                        ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_.sin_family = AF_UNSPEC;
                        }

                    ptr_estc_lcl_error_return_address = NULL;

                    /**
                    * Setting packet error data set
                    */
                    ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ = TRUE;
                    }
                }

            ptr_estc_lcl_cmsg = CMSG_NXTHDR(&estc_lcl_message, ptr_estc_lcl_cmsg);
            }
        }
    else
        {
        /**
        * Treat the case when function to receve the pong message succeeded
        */

        if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
            {
            ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_ = *((struct sockaddr_in *) &estc_lcl_ipv6_address);
            }
        else
            {
            ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_ = *((struct sockaddr_in6 *) &estc_lcl_ipv6_address);
            }
        }

    /**
    * Check if the socket has been closed by the other side
    */
    if(estc_lcl_number_of_bytes_receve == 0)
        {
        /**
        * Treat the case when the socket has been closed by the other side
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The socket has been closed by the other side\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the socket has been closed by the other side
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the socket has not been closed by the other side
        */
        }

    /**
    * Check if the ip family of the receve message is not the same as the destination
    */
    if(((struct sockaddr *) &estc_lcl_ipv6_address)->sa_family != ptr_cstc_pssd_ping_data->u16_ip_family_)
        {
        /**
        * Treat the case when the ip family of the receve message is not the same as the destination
        */

        ptr_cstc_pssd_ping_data->u8_global_status_packet_error_ = TRUE;

        ft_fprintf(STDERR_FILENO, "The receved packet is not from the same ip family than the destination\n");

        /**
        * Return to indicate the ip family of the receve message is not the same as the destination
        */
        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the ip family of the receve message is the same as the destination
        */

        if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
            {
            /**
            * Check if the ip address of the received message is not the same as the destination
            */
            if(ft_memcmp(&(((struct sockaddr_in *) &estc_lcl_ipv6_address)->sin_addr), (void *) &(ptr_cstc_pssd_ping_data->estc_ipv4_address_.sin_addr), sizeof(struct in_addr)) != 0)
                {
                /**
                * Treat the case when the ip address of the received message is not the same as the destination
                */

                ptr_cstc_pssd_ping_data->u8_global_status_packet_error_ = TRUE;
        //TODO -v

                ft_fprintf(STDERR_FILENO, "The ip of the receved packet is not the same than the destination ip\n");

                /**
                * Return to indicate the ip address of the received message is not the same as the destination
                */
                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when the ip address of the received message is the same as the destination
                */
                }
            }
        else
            {
            /**
            * Check if the ip address of the received message is not the same as the destination
            */
            if(ft_memcmp(&(((struct sockaddr_in6 *) &estc_lcl_ipv6_address)->sin6_addr), (void *) &(ptr_cstc_pssd_ping_data->estc_ipv6_address_.sin6_addr), sizeof(struct in6_addr)) != 0)
                {
                /**
                * Treat the case when the ip address of the received message is not the same as the destination
                */

                ptr_cstc_pssd_ping_data->u8_global_status_packet_error_ = TRUE;
        //TODO -v

                ft_fprintf(STDERR_FILENO, "The ip of the receved packet is not the same than the destination ip\n");

                /**
                * Return to indicate the ip address of the received message is not the same as the destination
                */
                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when the ip address of the received message is the same as the destination
                */
                }
            }
        }

    ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_ = estc_lcl_number_of_bytes_receve;

    /**
    * Searching the time to live value
    */
    ptr_cstc_pssd_ping_data->s32_ttl_ = 0;
    ptr_estc_lcl_cmsg = CMSG_FIRSTHDR(&estc_lcl_message);
    while(ptr_estc_lcl_cmsg != NULL)
        {
        if(((ptr_estc_lcl_cmsg->cmsg_level == IPPROTO_IP) && (ptr_estc_lcl_cmsg->cmsg_type == IP_TTL)) || ((ptr_estc_lcl_cmsg->cmsg_level == IPPROTO_IPV6) && (ptr_estc_lcl_cmsg->cmsg_type == IPV6_HOPLIMIT)))
            {
            ptr_u8_lcl_ttl = (uint8_t *) CMSG_DATA(ptr_estc_lcl_cmsg);

            if(ptr_u8_lcl_ttl != NULL)
                ptr_cstc_pssd_ping_data->s32_ttl_ = *ptr_u8_lcl_ttl;
            }

        ptr_estc_lcl_cmsg = CMSG_NXTHDR(&estc_lcl_message, ptr_estc_lcl_cmsg);
        }

    return (RETURN_SUCCESS);
    }

static const uint8_t   *u8_glbl_icmp_responses_str[] =
{
    [ICMP_DEST_UNREACH]     = (uint8_t *) "Destination Unreachable",
    [ICMP_SOURCE_QUENCH]    = (uint8_t *) "Source Quench",
    [ICMP_REDIRECT]         = (uint8_t *) "Redirect (change route)",
    [ICMP_ECHO]             = (uint8_t *) "Echo Request",
    [ICMP_TIME_EXCEEDED]    = (uint8_t *) "Time to live exceeded",
    [ICMP_PARAMETERPROB]    = (uint8_t *) "Parameter Problem",
    [ICMP_TIMESTAMP]        = (uint8_t *) "Timestamp Request",
    [ICMP_TIMESTAMPREPLY]   = (uint8_t *) "Timestamp Reply",
    [ICMP_INFO_REQUEST]     = (uint8_t *) "Information Request",
    [ICMP_INFO_REPLY]       = (uint8_t *) "Information Reply",
    [ICMP_ADDRESS]          = (uint8_t *) "Address Mask Request",
    [ICMP_ADDRESSREPLY]     = (uint8_t *) "Address Mask Reply"
};

static const uint8_t   *u8_glbl_icmp_v6_responses_str[] =
{
    [ICMPV6_DEST_UNREACH] = (uint8_t *) "Destination Unreachable",
    [ICMPV6_PKT_TOOBIG]   = (uint8_t *) "Packet too big",
    [ICMPV6_TIME_EXCEED]  = (uint8_t *) "Time exceeded: Hop limit",
    [ICMPV6_PARAMPROB]    = (uint8_t *) "Parameter problem",
    [ICMPV6_ECHO_REQUEST]    = (uint8_t *) "Echo request",
    [ICMPV6_ECHO_REPLY]    = (uint8_t *) "Echo reply",
};

static uint8_t *Fptr_u8__get_icmp_responses_str(uint32_t u32_pssd_value)
    {
    switch(u32_pssd_value)
        {
        case(ICMP_DEST_UNREACH):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_DEST_UNREACH]);
            break;
        case(ICMP_SOURCE_QUENCH):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_SOURCE_QUENCH]);
            break;
        case(ICMP_REDIRECT):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_REDIRECT]);
            break;
        case(ICMP_ECHO):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_ECHO]);
            break;
        case(ICMP_TIME_EXCEEDED):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_TIME_EXCEEDED]);
            break;
        case(ICMP_PARAMETERPROB):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_PARAMETERPROB]);
            break;
        case(ICMP_TIMESTAMP):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_TIMESTAMP]);
            break;
        case(ICMP_TIMESTAMPREPLY):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_TIMESTAMPREPLY]);
            break;
        case(ICMP_INFO_REQUEST):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_INFO_REQUEST]);
            break;
        case(ICMP_INFO_REPLY):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_INFO_REPLY]);
            break;
        case(ICMP_ADDRESS):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_ADDRESS]);
            break;
        case(ICMP_ADDRESSREPLY):
            return((uint8_t *) u8_glbl_icmp_responses_str[ICMP_ADDRESSREPLY]);
            break;
        default:
            return(NULL);
            break;
        }

    return (NULL);
    }

static uint8_t *Fptr_u8__get_icmp_v6_responses_str(uint32_t u32_pssd_value)
    {
    switch(u32_pssd_value)
        {
        case(ICMPV6_DEST_UNREACH):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_DEST_UNREACH]);
            break;
        case(ICMPV6_PKT_TOOBIG):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_PKT_TOOBIG]);
            break;
        case(ICMPV6_TIME_EXCEED):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_TIME_EXCEED]);
            break;
        case(ICMPV6_PARAMPROB):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_PARAMPROB]);
            break;
        case(ICMPV6_ECHO_REQUEST):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_ECHO_REQUEST]);
            break;
        case(ICMPV6_ECHO_REPLY):
            return((uint8_t *) u8_glbl_icmp_v6_responses_str[ICMPV6_ECHO_REPLY]);
            break;
        default:
            return(NULL);
            break;
        }

    return (NULL);
    }

static uint8_t Fu8__update_ping_rtt_value(struct cstc_ping_data *ptr_cstc_pssd_ping_data, suseconds_t estc_pssd_rtt)
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
    * Check if the rtt value in the structure ping data passed in argument of the function is not already set
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_rtt_already_set_ == FALSE)
        {
        /**
        * Treat the case when the rtt value in the structure ping data passed in argument of the function is not already set
        */

        ptr_cstc_pssd_ping_data->estc_rtt_min_          = estc_pssd_rtt;
        ptr_cstc_pssd_ping_data->estc_rtt_max_          = estc_pssd_rtt;
        ptr_cstc_pssd_ping_data->estc_rtt_total_        = estc_pssd_rtt;
        ptr_cstc_pssd_ping_data->estc_rtt_square_total_ = (estc_pssd_rtt * estc_pssd_rtt);

        ptr_cstc_pssd_ping_data->u8_global_status_rtt_already_set_ = TRUE;
        }
    else
        {
        /**
        * Treat the case when the rtt value in the structure ping data passed in argument of the function is already set
        */

        if(estc_pssd_rtt < ptr_cstc_pssd_ping_data->estc_rtt_min_)
            ptr_cstc_pssd_ping_data->estc_rtt_min_       = estc_pssd_rtt;
        if(estc_pssd_rtt > ptr_cstc_pssd_ping_data->estc_rtt_max_)
            ptr_cstc_pssd_ping_data->estc_rtt_max_       = estc_pssd_rtt;

        ptr_cstc_pssd_ping_data->estc_rtt_total_        += estc_pssd_rtt;
        ptr_cstc_pssd_ping_data->estc_rtt_square_total_ += (estc_pssd_rtt * estc_pssd_rtt);
        }

    return (RETURN_SUCCESS);
    }

static void Fv__display_timestamp(void)
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

        ft_printf("[0.0] ");
        }
    else
        {
        /**
        * Treat the case when function to get the actual time of the day succeeded
        */

        ft_printf("[%" PRIu64 ".%" PRIu64 "] ", estc_lcl_time_value.tv_sec, estc_lcl_time_value.tv_usec);
        }
    }

static uint8_t Fu8__checking_reply_packet_ipv4(struct cstc_ping_data *ptr_cstc_pssd_ping_data, uint8_t *ptr_u8_pssd_packet)
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
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    struct icmphdr  *ptr_estc_lcl_icmp_header;
    struct timeval  *ptr_estc_lcl_time_value;
    suseconds_t      estc_lcl_rtt;
    uint8_t          u8_lcl_return_from_function;
    uint8_t          u8_lcl_sender_address_str[INET_V4_V6_ADDRSTRLEN];
    uint8_t         *ptr_u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    estc_lcl_rtt                      = 0;
    ptr_estc_lcl_icmp_header          = NULL;
    ptr_estc_lcl_time_value           = NULL;
    ptr_u8_lcl_return_from_function   = NULL;
    u8_lcl_return_from_function       = RETURN_FAILURE;

    ft_memset(u8_lcl_sender_address_str, 0, INET_V4_V6_ADDRSTRLEN);

    /**
    * Getting data from packet
    */
    ptr_estc_lcl_icmp_header = (void *) ptr_u8_pssd_packet;
    ptr_estc_lcl_time_value  = (void *) (ptr_u8_pssd_packet + ICMP_HDR_SIZE);

    /**
    * Check if the icmp type is not echo reply
    */
    if((ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ == TRUE) && (ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_origin == SO_EE_ORIGIN_ICMP))
        {
        /**
        * Treat the case when the icmp type is not echo reply
        */

        if(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_.sin_family == AF_INET)
            {
            /**
            * Getting the sender address in ascii form
            */
            ptr_u8_lcl_return_from_function = NULL;
            ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET, (void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_.sin_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

            /**
            * Check if function to get the sender address in ascii form succeeded
            */
            if(ptr_u8_lcl_return_from_function == NULL)
                {
                /**
                * Treat the case when the function to get the sender address in ascii form failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to get the sender address in ascii form failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to get the sender address in ascii form succeeded
                */
                }
            }

        ptr_estc_lcl_icmp_header->type = ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_type;
        ptr_estc_lcl_icmp_header->code = ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_code;

        if(ptr_estc_lcl_icmp_header->type == ICMP_ECHO)
            return (RETURN_SUCCESS);

        if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[QUIET_OUTPUT] == FALSE)
            {
            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[VERBOSE_OUTPUT] != FALSE)
                {
                (void) Fv__display_receved_packet(ptr_cstc_pssd_ping_data, ptr_u8_pssd_packet);
                }

            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE)
                {
                ft_printf("\bE");
                fsync(STDOUT_FILENO);
                }
            else
                {
                if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[TIMESTAMP] != FALSE)
                    {
                    (void) Fv__display_timestamp();
                    }

                if(ptr_estc_lcl_icmp_header->type < sizeof(u8_glbl_icmp_responses_str))
                    {
                    ft_printf("From %s icmp_seq=%hu %s\n", u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence), Fptr_u8__get_icmp_responses_str(ptr_estc_lcl_icmp_header->type));
                    }
                else
                    {
                    ft_printf("From %s icmp_seq=%hu type = %u, code = %u\n", u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence), (uint32_t) ptr_estc_lcl_icmp_header->type, (uint32_t) ptr_estc_lcl_icmp_header->code);
                    }
                }
            }

        /**
        * Checking for overflow
        */
        if(ptr_cstc_pssd_ping_data->u32_number_errors_ < UINT32_MAX)
            {
            ptr_cstc_pssd_ping_data->u32_number_errors_++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    else if(ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ == FALSE)
        {
        /**
        * Treat the case when the icmp type is echo reply
        */

        /**
        * Getting the sender address in ascii form
        */
        ptr_u8_lcl_return_from_function = NULL;
        ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET, (void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_.sin_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

        /**
        * Check if function to get the sender address in ascii form succeeded
        */
        if(ptr_u8_lcl_return_from_function == NULL)
            {
            /**
            * Treat the case when the function to get the sender address in ascii form failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the sender address in ascii form failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the sender address in ascii form succeeded
            */
            }

        /**
        * Getting the retour time of the echo reply
        */
        estc_lcl_rtt = get_time() - ((ptr_estc_lcl_time_value->tv_sec * 1000000) + ptr_estc_lcl_time_value->tv_usec);

        if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[QUIET_OUTPUT] == FALSE)
            {
            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE)
                {
                ft_printf("\b");
                fsync(STDOUT_FILENO);
                }
            else
                {
                if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[TIMESTAMP] != FALSE)
                    {
                    (void) Fv__display_timestamp();
                    }

                if(((double) estc_lcl_rtt) / 1000.0f < 1.0f)
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.03f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                else if(((double) estc_lcl_rtt) / 1000.0f < 10.0f)
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.02f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                else
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.01f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_header->un.echo.sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                }
            }

        /**
        * Updating the rtt vale of the structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__update_ping_rtt_value(ptr_cstc_pssd_ping_data, estc_lcl_rtt);

        /**
        * Check if function to update the rtt vale of the structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to update the rtt vale of the structure ping data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to update the rtt vale of the structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to update the rtt vale of the structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to update the rtt vale of the structure ping data succeeded
            */
            }

        /**
        * Checking for overflow
        */
        if(ptr_cstc_pssd_ping_data->u32_number_packets_receved_ < UINT32_MAX)
            {
            ptr_cstc_pssd_ping_data->u32_number_packets_receved_++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

static uint8_t Fu8__checking_reply_packet_ipv6(struct cstc_ping_data *ptr_cstc_pssd_ping_data, uint8_t *ptr_u8_pssd_packet)
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
    * Check if the packet is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_packet == NULL)
        {
        /**
        * Treat the case when the packet is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the packet is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the packet is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the packet is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    struct icmp6hdr *ptr_estc_lcl_icmp_v6_header;
    struct timeval *ptr_estc_lcl_time_value;
    suseconds_t     estc_lcl_rtt;
    uint8_t         u8_lcl_return_from_function;
    uint8_t         u8_lcl_sender_address_str[INET_V4_V6_ADDRSTRLEN];
    uint8_t        *ptr_u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    estc_lcl_rtt                    = 0;
    ptr_estc_lcl_icmp_v6_header     = NULL;
    ptr_estc_lcl_time_value         = NULL;
    ptr_u8_lcl_return_from_function = NULL;
    u8_lcl_return_from_function     = RETURN_FAILURE;

    ft_memset(u8_lcl_sender_address_str, 0, INET_V4_V6_ADDRSTRLEN);

    /**
    * Getting data from packet
    */
    ptr_estc_lcl_icmp_v6_header = (void *) ptr_u8_pssd_packet;
    ptr_estc_lcl_time_value     = (void *) (ptr_u8_pssd_packet + ICMP_HDR_SIZE);

    /**
    * Check if the icmp type is not echo reply
    */
    if((ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ == TRUE) && (ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_origin == SO_EE_ORIGIN_ICMP6))
        {
        /**
        * Treat the case when the icmp type is not echo reply
        */

        if(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_.sin6_family == AF_INET6)
            {
            /**
            * Getting the sender address in ascii form
            */
            ptr_u8_lcl_return_from_function = NULL;
            ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET6, (void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_.sin6_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

            /**
            * Check if function to get the sender address in ascii form succeeded
            */
            if(ptr_u8_lcl_return_from_function == NULL)
                {
                /**
                * Treat the case when the function to get the sender address in ascii form failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to get the sender address in ascii form failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to get the sender address in ascii form succeeded
                */
                }
            }

        ptr_estc_lcl_icmp_v6_header->icmp6_type = ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_type;
        ptr_estc_lcl_icmp_v6_header->icmp6_code = ptr_cstc_pssd_ping_data->estc_error_packet_data_.ee_code;

        if(ptr_estc_lcl_icmp_v6_header->icmp6_type == ICMPV6_ECHO_REQUEST)
            return (RETURN_SUCCESS);

        if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[QUIET_OUTPUT] == FALSE)
            {
            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[VERBOSE_OUTPUT] != FALSE)
                {
                (void) Fv__display_receved_packet(ptr_cstc_pssd_ping_data, ptr_u8_pssd_packet);
                }

            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE)
                {
                ft_printf("\bE");
                fsync(STDOUT_FILENO);
                }
            else
                {
                if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[TIMESTAMP] != FALSE)
                    {
                    (void) Fv__display_timestamp();
                    }

                if(ptr_estc_lcl_icmp_v6_header->icmp6_type < sizeof(u8_glbl_icmp_responses_str))
                    {
                    ft_printf("From %s icmp_seq=%hu %s\n", u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_v6_header->icmp6_sequence), Fptr_u8__get_icmp_v6_responses_str(ptr_estc_lcl_icmp_v6_header->icmp6_type));
                    }
                else
                    {
                    ft_printf("From %s icmp_seq=%hu type = %u, code = %u\n", u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_v6_header->icmp6_sequence), (uint32_t) ptr_estc_lcl_icmp_v6_header->icmp6_type, (uint32_t) ptr_estc_lcl_icmp_v6_header->icmp6_code);
                    }
                }
            }

        /**
        * Checking for overflow
        */
        if(ptr_cstc_pssd_ping_data->u32_number_errors_ < UINT32_MAX)
            {
            ptr_cstc_pssd_ping_data->u32_number_errors_++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    else if(ptr_cstc_pssd_ping_data->u8_global_status_packet_error_data_ == FALSE)
        {
        /**
        * Treat the case when the icmp type is echo reply
        */

        /**
        * Getting the sender address in ascii form
        */
        ptr_u8_lcl_return_from_function = NULL;
        ptr_u8_lcl_return_from_function = (uint8_t *) inet_ntop(AF_INET6, (void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_.sin6_addr), (char *) u8_lcl_sender_address_str, INET_V4_V6_ADDRSTRLEN);

        /**
        * Check if function to get the sender address in ascii form succeeded
        */
        if(ptr_u8_lcl_return_from_function == NULL)
            {
            /**
            * Treat the case when the function to get the sender address in ascii form failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the sender address in ascii form failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the sender address in ascii form failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the sender address in ascii form succeeded
            */
            }

        /**
        * Getting the retour time of the echo reply
        */
        estc_lcl_rtt = get_time() - ((ptr_estc_lcl_time_value->tv_sec * 1000000) + ptr_estc_lcl_time_value->tv_usec);

        if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[QUIET_OUTPUT] == FALSE)
            {
            if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[FLOOD] != FALSE)
                {
                ft_printf("\b");
                fsync(STDOUT_FILENO);
                }
            else
                {
                if(ptr_cstc_pssd_ping_data->sstc_argument_.ptr_u8_simple_options_[TIMESTAMP] != FALSE)
                    {
                    (void) Fv__display_timestamp();
                    }

                if(((double) estc_lcl_rtt) / 1000.0f < 1.0f)
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.03f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_v6_header->icmp6_sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                else if(((double) estc_lcl_rtt) / 1000.0f < 10.0f)
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.02f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_v6_header->icmp6_sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                else
                    {
                    ft_printf("%ld bytes from %s: icmp_seq=%u ttl=%u time=%.01f ms\n", ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_, u8_lcl_sender_address_str, Fu16__reverse_endianness(ptr_estc_lcl_icmp_v6_header->icmp6_sequence), ptr_cstc_pssd_ping_data->s32_ttl_, ((double) estc_lcl_rtt) / 1000.0f);
                    }
                }
            }

        /**
        * Updating the rtt vale of the structure ping data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__update_ping_rtt_value(ptr_cstc_pssd_ping_data, estc_lcl_rtt);

        /**
        * Check if function to update the rtt vale of the structure ping data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to update the rtt vale of the structure ping data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to update the rtt vale of the structure ping data failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to update the rtt vale of the structure ping data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to update the rtt vale of the structure ping data succeeded
            */
            }

        /**
        * Checking for overflow
        */
        if(ptr_cstc_pssd_ping_data->u32_number_packets_receved_ < UINT32_MAX)
            {
            ptr_cstc_pssd_ping_data->u32_number_packets_receved_++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

uint8_t Fu8__receve_pong(struct cstc_ping_data *ptr_cstc_pssd_ping_data)
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
    uint8_t u8_lcl_return_from_function;
    uint8_t u8_lcl_packet[PACKET_SIZE];

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    ft_memset(u8_lcl_packet, 0, sizeof(u8_lcl_packet));

    /**
    * Reseting the receve ip address structure of the structure ping data
    */
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv4_address_));
    ft_memset((void *) &(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_), 0, sizeof(ptr_cstc_pssd_ping_data->estc_receve_ipv6_address_));

    /**
    * Reseting the packet receve information of the structure ping data
    */
    ptr_cstc_pssd_ping_data->estc_number_of_bytes_receve_ = 0;
    ptr_cstc_pssd_ping_data->s32_ttl_                     = 0;

    /**
    * Getting packet from destination
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__getting_packet(ptr_cstc_pssd_ping_data, u8_lcl_packet);

    /**
    * Check if function to get packet from destination succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get packet from destination failed
        */

        if(u8_lcl_return_from_function == RETURN_NOT_FAILURE_BUT_NOT_SUCCESS)
            {
            return (RETURN_SUCCESS);
            }

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get packet from destination failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to get packet from destination failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to get packet from destination succeeded
        */
        }

    /**
    * Check if the receved packet have an error
    */
    if(ptr_cstc_pssd_ping_data->u8_global_status_packet_error_ == FALSE)
        {
        /**
        * Treat the case when the receved packet have an error
        */

        /**
        * Check if the actual protocol is ip v4
        */
        if(ptr_cstc_pssd_ping_data->u16_ip_family_ == AF_INET)
            {
            /**
            * Treat the case when the actual protocol is ip v4
            */

            /**
            * Checking the ipv4 reply packet
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__checking_reply_packet_ipv4(ptr_cstc_pssd_ping_data, u8_lcl_packet);

            /**
            * Check if function to check the ipv4 reply packet succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to check the ipv4 reply packet failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to check the ipv4 reply packet failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to check the ipv4 reply packet failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to check the ipv4 reply packet succeeded
                */
                }
            }
        else
            {
            /**
            * Treat the case when the actual protocol is ip v6
            */

            /**
            * Checking the ipv6 reply packet
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__checking_reply_packet_ipv6(ptr_cstc_pssd_ping_data, u8_lcl_packet);

            /**
            * Check if function to check the ipv6 reply packet succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to check the ipv6 reply packet failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to check the ipv6 reply packet failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to check the ipv6 reply packet failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to check the ipv6 reply packet succeeded
                */
                }
            }
        }
    else
        {
        /**
        * Treat the case when the receved packet have no error
        */
        }

    return (RETURN_SUCCESS);
    }
