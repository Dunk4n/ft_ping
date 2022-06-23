#ifndef FT_PING
# define FT_PING

#define _GNU_SOURCE

# include <inttypes.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>
# include <netinet/ip_icmp.h>
# include <linux/icmpv6.h>
# include <math.h>
# include <errno.h>
# include <linux/errqueue.h>

# include "../libft/libft.h"

# define DEVELOPEMENT
# define RETURN_FAILURE (1)
# define RETURN_SUCCESS (0)
# define RETURN_NOT_FAILURE_BUT_NOT_SUCCESS (2)
# define ARGUMENT_CONTINUE (0)
# define ARGUMENT_ERROR (1)
# define ARGUMENT_NO_CONTINUE (2)
# define FALSE (0)
# define TRUE (1)
# define NIL            ('\0')

# define FIRST_BIT      (0x01)
# define SECOND_BIT     (0x02)
# define THIRD_BIT      (0x04)
# define FOURTH_BIT     (0x08)
# define FIFTH_BIT      (0x10)
# define SIXTH_BIT      (0x20)
# define SEVENTH_BIT    (0x40)
# define EIGHTH_BIT     (0x80)

# define NOT_FIRST_BIT      (0xFE)
# define NOT_SECOND_BIT     (0xFD)
# define NOT_THIRD_BIT      (0xFB)
# define NOT_FOURTH_BIT     (0xF7)
# define NOT_FIFTH_BIT      (0xEF)
# define NOT_SIXTH_BIT      (0xDF)
# define NOT_SEVENTH_BIT    (0xBF)
# define NOT_EIGHTH_BIT     (0x7F)

enum e_simple_option_list
{
    VERBOSE_OUTPUT = 0,
    HELP,
    FLOOD,
    NUMERIC_OUTPUT,
    QUIET_OUTPUT,
    USE_IPV4,
    USE_IPV6,
    TIMESTAMP,

    SIMPLE_OPTION_NUMBER,
    NO_SIMPLE_OPTION                                                           // range UINT8_MAX
};

enum e_argument_option_list
{
    PRELOAD = 0,
    INTERFACE,
    MARK,
    PMTUDISC,
    DEADLINE,
    TIMEOUT,
    PATTERN,
    QUALITY_OF_SERVICE,
    SNDBUF,
    TTL,
    COUNT_ECHO,

    ARGUMENT_OPTION_NUMBER,
    NO_ARGUMENT_OPTION                                                         // range UINT8_MAX
};

typedef struct  argument_s
{
    uint8_t              u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y / 0 = N
    // SECOND_BIT    Argument error             1 = Y / 0 = N

    uint8_t              ptr_u8_simple_options_[SIMPLE_OPTION_NUMBER];
    uint8_t              ptr_u8_argument_options_[ARGUMENT_OPTION_NUMBER];
    uint8_t             *dbl_ptr_u8_argument_option_value_str_[ARGUMENT_OPTION_NUMBER];
    uint8_t            **dbl_ptr_u8_additional_argument_str_;
    uint64_t             u64_number_of_additional_argument_;
}                argument_t;

extern const uint8_t *simple_options[SIMPLE_OPTION_NUMBER];

extern const uint8_t *argument_options[ARGUMENT_OPTION_NUMBER];

uint8_t Fu8__structure_argument_init(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_close(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_reset(argument_t *ptr_sstc_pssd_argument);
void    Fv__structure_argument_display(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__load_data_from_argument(argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_program_arguments);

void Fv__help(void);

# define INET_V4_V6_ADDRSTRLEN ((INET6_ADDRSTRLEN > INET_ADDRSTRLEN) ? (INET6_ADDRSTRLEN + 1) : (INET_ADDRSTRLEN + 1))

# define IP_HDR_SIZE            (20)
# define ICMP_HDR_SIZE          ICMP_MINLEN
# define ICMP_PAYLOAD_SIZE      (56)
# define PACKET_SIZE            (IP_HDR_SIZE + ICMP_HDR_SIZE + ICMP_PAYLOAD_SIZE)

# define FT_PING_NUMBER_OF_SECONDS_BETWEEN_PING (1)

# define ROOT_USER (0)

# define ONE_SECOND_IN_MICROSECOND (1000000)
# define FLOOD_WAIT (3500)
# define PRELOAD_PING_NOT_ROOT_MAX (3)
# define PATTERN_MAX_SIZE (16)

struct cstc_ping_data
    {
    union
        {
        uint8_t u8_global_status_;

        struct
            {
            // FIRST_BIT     Structure initialized      1 = Y / 0 = N
            uint8_t u8_global_status_struct_init_ : 1;

            // SECOND_BIT    RTT already set            1 = Y / 0 = N
            uint8_t u8_global_status_rtt_already_set_ : 1;

            // THIRD_BIT     Silent error               1 = Y / 0 = N
            uint8_t u8_global_status_silent_error_ : 1;

            // FOURTH_BIT    Packet error               1 = Y / 0 = N
            uint8_t u8_global_status_packet_error_ : 1;

            // FIFTH_BIT     Packet error data          1 = Y / 0 = N
            uint8_t u8_global_status_packet_error_data_ : 1;
            };
        };

    uint16_t   u16_ip_family_;

    union
    {
        struct sockaddr_in  estc_ipv4_address_;
        struct sockaddr_in6 estc_ipv6_address_;
    };

    uint8_t     u8_ip_address_str_[INET_V4_V6_ADDRSTRLEN];

    int32_t     s32_socket_;

    uint16_t    u16_packet_sequence_;

    suseconds_t estc_rtt_min_;
    suseconds_t estc_rtt_max_;
    suseconds_t estc_rtt_total_;
    suseconds_t estc_rtt_square_total_;
    suseconds_t estc_start_time_;

    uint32_t    u32_number_packets_transmitted_;
    uint32_t    u32_number_packets_receved_;
    uint32_t    u32_number_errors_;
    uint32_t    u32_max_number_packets_;

    ssize_t     estc_number_of_bytes_receve_;
    int32_t     s32_ttl_;
    union
    {
        struct sockaddr_in  estc_receve_ipv4_address_;
        struct sockaddr_in6 estc_receve_ipv6_address_;
    };

    struct sock_extended_err estc_error_packet_data_;

    int32_t     s32_echo_tll_;

    int32_t     s32_mark_;

    int32_t     s32_send_buffer_size_;

    uint8_t     u8_pattern_[PATTERN_MAX_SIZE];
    uint8_t     u8_pattern_size_;

    argument_t  sstc_argument_;
    };

suseconds_t get_time(void);

/**
* Ping_data
*/
uint8_t Fu8__close_cstc_ping_data(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
uint8_t Fu8__get_value_from_ping_argument(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
uint8_t Fu8__init_cstc_ping_data(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
uint8_t Fu8__send_ping(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
uint8_t Fu8__start_connection(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
void    Fv__display_cstc_ping_data(struct cstc_ping_data *ptr_cstc_pssd_ping_data);
void    Fv__display_ping_statistic(struct cstc_ping_data *ptr_cstc_pssd_ping_data);

extern struct cstc_ping_data cstc_glbl_ping_data;

/**
* Packet
*/
uint8_t Fu8__getting_packet(struct cstc_ping_data *ptr_cstc_pssd_ping_data, uint8_t *ptr_u8_pssd_packet);
uint8_t Fu8__receve_pong(struct cstc_ping_data *ptr_cstc_pssd_ping_data);

/**
* Signal
*/
void Fv__signal_handler_exit(__attribute__((unused)) int signal);
void Fv__signal_handler_alarm(__attribute__((unused)) int signal);

uint16_t ft_htons(uint16_t value);

#endif /* FT_PING */
