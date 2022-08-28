/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-31 10:06:02
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-31 12:03:27
 */

#define MAX_SIZE 256
enum class MQType
{
    TYPEA,
    TYPEB,
    TYPEC
};

typedef struct MQData
{
    MQType mqStatus;
    char data[MAX_SIZE];
} MQData_t;