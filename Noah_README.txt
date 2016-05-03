Please feel free to email me (nwolfey21@gmail.com) or stop my my office (MRC 330D) if/when you have questions.

Folders:
- Min-UR-95: Simulation run using the Minimal routing algorithm with a Uniform Random (UR) message workload and message injection rate of 95% link bandwidth.
- NonMin-UR-100: Same as above with NonMinimal routing algorithm and message injection rate of 100% link bandwidth.

- vc-occupancy: virtual channel occupancy data. Each file is indexed to represent the given router in the simulation. Each ethernet cable 
					port/channel in a router has 4 virtual channels which store messages when the link is utilized. There should also be 
					a .m matlab file within each vc-occupancy folder which has the algorithms to extract the data.

Files:
- slimfly-results-log: (unfortunately only file with headers) Holds information for each simulation run. Each row is another execution
						of the slimfly model with different input parameters and corresponding performance results.
- slimfly_router_sends_recvs_log.txt: Holds number of messages sent and received by each router over time. The left most column is virutal time (0-99).
- slimfly_router_sends_recvs_plot_script.m: Holds the algorithms used to extract the router data and visualize it.
- slimfly_terminal_sends_recvs_log.txt: Holds number of messages sent and received by each terminal over time. The left most column is virutal time (0-99).
- slimfly_terminal_sends_recvs_plot_script.m: Holds the algorithms used to extract the terminal data and visualize it.
