/*
 * debug.h
 *
 *  Created on: 2 Sep 2020
 *      Author: mgrosvenor
 */

#ifndef DEBUG_H_
#define DEBUG_H_


/*
 * A little bit of self contained debugging help from
 * https://github.com/mgrosvenor/libchaste/blob/master/utils/debug.c
 */

typedef enum {
    IFWR_DBG,   //Debug message
    IFWR_ERR,   //Error message
    IFWR_FAT,   //Fatal message
    IFWR_WARN   //Warning message
} ifwr_dbg_mode_e;

#define OUTPUT_TO STDERR_FILENO


#define ERR( /*format, args*/...)  ifwr_err_helper(__VA_ARGS__, "")
#define ifwr_err_helper(format, ...) ifwr_dbg_out_(true, IFWR_ERR, __LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )
#define ERR2( /*format, args*/...)  ifwr_err_helper2(__VA_ARGS__, "")
#define ifwr_err_helper2(format, ...) ifwr_dbg_out_(false, IFWR_ERR, __LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )

#define FAT( /*format, args*/...)  ifwr_fat_helper(__VA_ARGS__, "")
#define ifwr_fat_helper(format, ...) ifwr_dbg_out_(true, IFWR_FAT, __LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )
#define FAT2( /*format, args*/...)  ifwr_fat_helper2(__VA_ARGS__, "")
#define ifwr_fat_helper2(format, ...) ifwr_dbg_out_(false, IFWR_FAT, __LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )

#ifndef NDEBUG
    //int ifwr_dbg_out_(ch_bool info, int line_num, const char* filename, const char* function,  const char* format, ... );
    #define DBG( /*format, args*/...)  ifwr_dbg_helper(__VA_ARGS__, "")
    #define ifwr_dbg_helper(format, ...) ifwr_dbg_out_(true,IFWR_DBG,__LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )
    #define DBG2( /*format, args*/...)  ifwr_dbg_helper2(__VA_ARGS__, "")
    #define ifwr_dbg_helper2(format, ...) ifwr_dbg_out_(false,IFWR_DBG,__LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )
    #define WARN( /*format, args*/...)  ifwr_dbg_helper3(__VA_ARGS__, "")
    #define ifwr_dbg_helper3(format, ...) ifwr_dbg_out_(true,IFWR_WARN,__LINE__, __FILE__, __FUNCTION__, format, __VA_ARGS__ )
#else
    #define DBG( /*format, args*/...)
    #define DBG2( /*format, args*/...)
    #define WARN( /*format, args*/...)
#endif


int ifwr_dbg_out_(
        bool info,
        ifwr_dbg_mode_e mode,
        int line_num,
        const char* filename,
        const char* function,
        const char* format, ... );



#endif /* DEBUG_H_ */
