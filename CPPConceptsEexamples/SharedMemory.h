/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-30 23:40:40
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-30 23:45:18
 */

#include <string.h>
#include <iostream>
enum class SharedMemStatus
{
    NOT_READY,
    FILLED,
    TAKEN
};

typedef struct SMData
{
    SharedMemStatus status;
    char data[256];
} SMData_t;