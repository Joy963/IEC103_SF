/*
 * TcpNet.h
 *
 *  Created on: Jun 14, 2015
 *      Author: root
 */

#ifndef TCPNET_H_
#define TCPNET_H_

#include <string>
#include <netinet/in.h>

#include "Inet.h"

class TcpNet : public Inet
{
public:
	/*
	 * @Desc: 初始化
	 * @Param: 读取数据存放地址
	 * @Param: 读取数据存放地址
	 */
	TcpNet(const std::string & serverAddr, uint16_t serverPort);
	virtual ~TcpNet();

	/*
	 * @Desc: 进行通讯连接
	 * @Return: 连接成功或失败
	 */
	virtual bool Connect();

	/*
	 * @Desc: 读取数据
	 * @Param: 读取数据存放地址
	 * @Param: 读取数据的最大长度
	 * @Return: 读取的数据长度
	 */
	virtual int32_t Read(char * pRecvData, uint32_t dataMaxLen);

	/*
	 * @Desc: 发送数据
	 * @Param: 发送数据存放地址
	 * @Param: 发送的数据的长度
	 * @Return: 发送的数据长度
	 */
	virtual int32_t Write(const char * pSendData, uint32_t dataLen);

	/*
	 * @Desc: 断开通讯连接
	 * @Return: 成功或失败
	 */
	virtual bool DisConnect();
private:
	sockaddr_in  m_serverAddr;
	std::string  m_serverAddrStr;
};

#endif /* TCPNET_H_ */
