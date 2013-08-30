#define  APP_GLOBALS

#include "app.h"
#include "STC12C5A60S2.H"
#include "adc.h"
#include <stdio.h>
#include <string.h>

u8 xdata tx_buf[RBUF_SIZE];  //���崮�ڽ��յ�������  ͨ��tcp���ͳ�ȥ
extern u8 client_connect_flag;


char xdata  htmlpage[] =
{
"HTTP/1.0 200 OK\nContent-Type: text/html\n\n"
"<html><meta http-equiv=refresh content=3>"
"<body><center>"
"<h1>����WEB�ļ��ϵͳ��Ʋ���ҳ��</h1>"
"<h3>����������:</h3><br>"
"<p>�����ť�Կ�����ر�LED 1��ӦLED�� 0��ӦLED��</p></center>"
"<form action=swc.html><table align=center>"
"<tr align=center>"
"<td>P1_7:&nbsp<input type=submit name=sw7 value=1></td>"	  //0x147
"<td>P1_6:&nbsp<input type=submit name=sw6 value=1></td></tr></table></form>"	// 0x17e
"<center><h3>ƽ̨��ѹ: 05.00V</h3>"	 //0x1ae-0x1af :'10'
"</body></html>"																		   
/*
"<HTML><HEAD><meta http-equiv=refresh content=1><TITLE>Welcome to BD7BQ's Website</TITLE></HEAD>"
"<table border=\"1\" width=\"49%\" height=\"81\">"
"<tr>"
"<td width=\"100%\" colspan=\"2\" height=\"24\">"
"<p align=\"center\">"
"<font color=\"#FF0000\">"
"����,��ӭ�����ҵĵ�Ƭ����̫�����԰�</font></td>"
"</tr>"
"<tr>"
"<td width=\"48%\" align=\"center\" height=\"45\"><font size=\"6\">�¶�</font></td>"
"<td width=\"52%\" align=\"center\" height=\"45\"><font size=\"6\">28.5��</font></td>"
"</tr>"
"</table>"
"<br>"
"���Ǳ����������00000��������,Good luck to you .</br>"
"</HTML>" */
};
struct httpd_state xdata hs;
static unsigned int tt; //the value of temperature
void listen_init(void)
{
	//80�˿�����webҳ��
	uip_listen(HTONS(8079));  //���ڴ��ڲ���������
	uip_listen(HTONS(8080));  //�����շ�����
	uip_listen(HTONS(80));	/* http server */
}
sbit P1_7=P1^7;
sbit P1_6=P1^6;

void appcall(void)
{
	u16 i;

  switch(uip_conn->lport) 
  {
  /* http port */
  	case HTONS(80):
		/* when syn_rcv the uip_connected() return not zero ,it means 
		   client connect to host*/
		if(uip_connected()) { 
		 	/* init the byte count */
			hs.count = 0;					
			return;
		}
		else if(uip_poll()) {	 
		/* If we are polled ten times, we abort the connection. This is
		   because we don't want connections lingering indefinately in
		   the system.  */
			if(hs.count++ >= 10) {
				uip_abort();
			}
			return;
		}
		else if(uip_newdata())
		{	if(uip_appdata[0]!='G' || uip_appdata[1]!='E' || uip_appdata[2]!='T' || uip_appdata[3]!=' ')
				uip_abort();
			/* control the led on and off */
			/* 0123456789abcdef */
			/* GET /swc.html?sw7=1 */
			if(uip_appdata[4]=='/' && uip_appdata[5]=='s' && uip_appdata[6]=='w' && uip_appdata[7]=='c')
			{	if(uip_appdata[16]=='7')
				{	if(uip_appdata[18]=='1') 
					{	P1_7=0;
						htmlpage[0x146]='0';
					}
					else
					{	P1_7=1;
						htmlpage[0x146]='1';
						
					}
				}
				if(uip_appdata[16]=='6')
				{	if(uip_appdata[18]=='1') 
					{	P1_6=0;
						htmlpage[0x17d]='0';
					}
					else
					{	P1_6=1;
						htmlpage[0x17d]='1';
						
					}
				}
			}

			{
				xdata u8 val[16];
				sprintf(val,"%04.2f",get_adc_val()*5.0/1024);
				memcpy(&htmlpage[0x1ae],val,5);
			}
//			tt = 0;
//			htmlpage[0x1ae]=(unsigned char)(tt>>8)/10+'0';	 //����
//			htmlpage[0x1af]=(unsigned char)(tt>>8)%10+'0';
//
//			htmlpage[0x1af+2]=(tt & 0x00ff)/10+'0';			//С��
//			htmlpage[0x1af+3]=(tt & 0x00ff)%10+'0';
			

			hs.dataptr=htmlpage;
			hs.count=sizeof(htmlpage)-1;
		}


		//���յ�client��ack����˵����ǰ�������ѳɹ����ͣ�����ʣ�µ����ݴ�������û����Ҫ�����͹ر�����		  
		if(uip_acked()) {//��û�����꣬���ȺͿ�ʼָ�뻹�Ǵ���hs->count ��hs->dataptr��		
			if(hs.count >= uip_conn->len) {	 /* uip_conn.len contain the bytes sent just now */
				hs.count -= uip_conn->len;
				hs.dataptr += uip_conn->len;
			}
			else {
				hs.count = 0;
			}
		
			if(hs.count == 0) {		   			
				uip_close();	 /* ���ݷ�����ɣ��ر����� */
			}
		}
		/* ��û���ط���������ESTABLISHED״̬ʱ���Ż����uip_flags = UIP_POLL; */
		if(!uip_poll()) {
		/* Send a piece of data, but not more than the MSS of the	connection.	*/
			uip_send(hs.dataptr, hs.count);
		}

		return;
			
	case HTONS(8079):		//*���ڲ�������	
		if (uip_newdata())	//*UIP_CONNECTED UIP_NEWDATA UIP_ACKDATA
		{	if(uip_appdata[0]=='s' && uip_appdata[1]=='e' && uip_appdata[2]=='t')
			if(uip_appdata[3]=='c' && uip_appdata[4]=='o' && uip_appdata[5]=='m')
			{			
			//	u8 *str[]={"24","48","96","192","288","384","576","1152"};
				u8 code tab[] = {112,184,220,238,244,247,250,253};
				xputs("set ok, please change buard rate\r\n");
				Delay_x(500);

				i = uip_appdata[6] - '0';
				if(i >= 0 && i <=7)
				{
					TH1 = tab[i];
					TL1=TH1;
				}


//				switch(uip_appdata[6])
//				{	case '0':  //2400bps
//						TH1 = 112;
//						//RCAP2H=0xf7;
//						//RCAP2L=0x00;
//						//puts("300bps\r\n");
//						break;
//					case '1':
//						TH1 = 184;	//4800bps
//						//RCAP2H=0xfb;
//						//RCAP2L=0x80;
//						//puts("600bps\r\n");
//						break;
//					case '2':
//						TH1 = 220; //9600bps
//						//RCAP2H=0xfd;
//						//RCAP2L=0xc0;
//						//puts("1200bps\r\n");
//						break;
//					case '3':
//						TH1 = 
//						//RCAP2H=0xfe;
//						//RCAP2L=0xe0;
//						//puts("2400bps\r\n");
//						break;
//					case '4':
//						//RCAP2H=0xff;
//						//RCAP2L=0x70;
//						//puts("4800bps\r\n");
//						break;
//					case '5':
//						//RCAP2H=0xff;
//						//RCAP2L=0xb8;
//						//puts("9600bps\r\n");
//						break;
//					case '6':
//						//RCAP2H=0xff;
//						//RCAP2L=0xdc;
//						//puts("19200bps\r\n");
//						break;
//					case '7':
//						//RCAP2H=0xff;
//						//RCAP2L=0xee;
//						//puts("38400bps\r\n");
//						break;
//					case '8':
//						//RCAP2H=0xff;
//						//RCAP2L=0xf4;
//						//puts("57600bps\r\n");
//						break;
//					case '9':
//						//RCAP2H=0xff;
//						//RCAP2L=0xfa;
//						//puts("115200bps\r\n");
//						break;
//					default:
//						//RCAP2H=0xff;
//						//RCAP2L=0xb8;
//						//puts("9600bps\r\n");
//						break;
//				}					
			}
		}		
	return;	   
	/*---------------------------------------------------------------------------------*/
	//�������ݴ��͵Ķ˿�	
	case HTONS(8080):
		if (uip_newdata())	//UIP_CONNECTED UIP_NEWDATA UIP_ACKDATA
		{
			if(uip_len)
			{
				for(i=0; i<uip_len; i++ )
				{
					SendChar(uip_appdata[i]);
//					if(-1 != SendChar(uip_appdata[i]))
//						i++;
				}
			}	
		}
		if(uip_poll())
		{
			u16 dt_len = SIO_RBUFLEN;
			
			if(dt_len > 0)
			{
				for(i=0; i<dt_len; i++)
				{
					tx_buf[i] = GetKey();
				}	
				uip_slen = dt_len;
				uip_send(tx_buf,uip_slen);
			}
		}					
	return;	  
/*---------------------------------------------------------------------------------*/
//����clientʱ���ⲿ����Ҫȡ��
//	default:
//    uip_abort();
//    break;
  }
  
  if(uip_conn->rport == HTONS(8888))
  {
	if(uip_connected())
	{
		code char hello[] = "Hello world\r\n"; 
		xlog("��������\r\n");
		uip_slen = strlen(hello);
		uip_send(hello,uip_slen);
		client_connect_flag = 1;
	}
	else if(uip_newdata())
	{
		uip_send(uip_appdata,uip_len);	//��ԭ�����	
	}
	else if(uip_aborted())
	{
		client_connect_flag = 0;
		xlog("rst ");
	}
	else if(uip_closed())
	{
		client_connect_flag = 0;
		xlog("disc ");	
	}
  }  
}