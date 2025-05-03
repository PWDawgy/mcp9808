#ifndef MOCK_SDK_ERRORS_H
#define MOCK_SDK_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

    #define NRFX_SUCCESS 0
    #define NRFX_ERROR_BUSY 1
    #define NRFX_ERROR_INVALID_PARAM 2
    #define NRFX_ERROR_INTERNAL 3

    typedef int ret_code_t;
#ifdef __cplusplus
}
#endif

#endif // MOCK_SDK_ERRORS_H