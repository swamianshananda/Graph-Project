# khattri2-anshcs2-tyxia2
Final Project

INTRODUCTION

Hello!!! We are Ansh Shah, Neel Khattri, and Taylor Xia, and this is our cs225 final project. For our final project we are using a twitter sub data set, and are modeling it so that we have incoproated Floyd-Warshall's shortest path algorithim, and also a Betweeness Centriality calculation. 

PURPOSE
We are running the Floyd-Warshall algorithm to find the shortest number of connections between two nodes. This way two users can use the least amount of work to figure out how they knew each other. We are running a Betweeness Centriality calculation to show how "popular" or "connected" someone is based of their Betweeness Centriality value.

INSTRUCTIONS

The data set we have used is called twitter_combined.txt. The format is as follows

123456789 987654321 <br />
12345 54931 <br />
12443241 54254354 <br />
...
The number in the left hand column is a user ID of type unsigned long. Then there is a space. The number in the right column is a differnet user ID of type unsigned long. NO SPACES after that it is a new line. Each line represents a DIRECTED connection, in this case... user with userId 123456789 follows user with userId 987654321. The left column follows the right column. This is a list of connections is what our dataset is. If you would like to use a different dataset of the same format, go into the main.cpp file and switch the "twitter_combined.txt" to the name of the txt file with the SAME DATA FORMAT.
<br />
HERE IS A LINK TO OUR DATASET: http://snap.stanford.edu/data/ego-Twitter.html<br />
*please note that we used the twitter_combined.txt.gz file and then switched/converted it to a txt file (by switching the file ending) where it listed out the connections as seen above. We did this because no computers/applications we had to could read the format, and we confirmed it with our TA Alex Shi who said it was good.
<br />
We have provided test cases. Once downloaded please run "make test" then "./test" this will show you how our test cases work. Afterwards if you want to run the program fully run "make" then "./project". This is our executable where it runs the whole program and displays the BFS output in the file BFS.txt. It also runs the Floyd-Warshall and Betweeness Centriality and will print out the Betweeness Centriality values for each node in the file called Betweeness Centriality Output.txt. 


TODO

1) Finish Betweeness central (it is relying on indexes)
2) Update GOALS and DEVELOPMENT
3) Make presentation and video and report
4) Finish readme