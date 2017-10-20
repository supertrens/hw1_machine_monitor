/***************************************************
 * Authour    : 皮宜恩                              *
 * Student id : F74027036                          *
 * Date       : 10/13/2017                         *
 * Program    : HW1        			               *
 * Information: Please read README file            *
 *                                                 *
 **************************************************/

 Socket programming requirements:
1) Write one server & one client
   	1.1) Client can ask process information like pid from server.
	1.2) Server MUST read process information under /proc.
	1.3) Please refer page 4 for the detail.

2) Multi-threads server
	2.1) Server should have a thread to listen connection request of clients.
	2.2) When server receive connection request, server create one thread 
	     to handle the request. Then each thread do the task client requested.
	2.3) Server can be connected by multi-clients at the same time

3) Implement querying interface or GUI.

4) Query items include-
	4.1) All processes id, process name, command line, process status, parent’s PID, child’s PID, thread’s IDs, all ancients of PIDs, virtual memory size, physical memory size, exit.

5) Coding style-(when push to server)
	5.1) Follow astyle in Gitlab server.
	5.2) Ex: astyle –style=linux –indent=tab –max-code-length=80 ${file}