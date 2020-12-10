# khattri2-anshcs2-tyxia2


#**INTRODUCTION**

Hello!!! We are Ansh Shah, Neel Khattri, and Taylor Xia, and this is our cs225 final project. For our final project we are using a twitter sub data set, and are modeling it so that we have incoproated Floyd-Warshall's shortest path algorithim, and also a Betweeness Centriality calculation. 

#**PURPOSE**

We are running the Floyd-Warshall algorithm to find the shortest number of connections between two nodes. This way two users can use the least amount of work to figure out how they knew each other. We are running a Betweeness Centriality calculation to show how "popular" or "connected" someone is based of their Betweeness Centriality value.

#**INSTRUCTIONS**

The data set we have used is called twitter_combined.txt. However due to that data being too large...we are using another data called Wiki-Votes.txt as concept of proof. The format is as follows

123456789 987654321 <br />
12345 54931 <br />
12443241 54254354 <br />
...
The number in the left hand column is a user ID of type unsigned long. Then there is a space. The number in the right column is a differnet user ID of type unsigned long. NO SPACES after that it is a new line. Each line represents a DIRECTED connection, in this case... user with userId 123456789 follows user with userId 987654321. The left column follows the right column. This is a list of connections is what our dataset is. If you would like to use a different dataset of the same format, go into the main.cpp file and switch the "twitter_combined.txt" to the name of the txt file with the SAME DATA FORMAT.
<br />
_HERE IS A LINK TO OUR DATASET_: http://snap.stanford.edu/data/ego-Twitter.html<br />
*please note that we used the twitter_combined.txt.gz file and then switched/converted it to a txt file (by switching the file ending) where it listed out the connections as seen above. We did this because no computers/applications we had to could read the format, and we confirmed it with our TA Alex Shi who said it was good.
<br />
We have provided test cases. Once downloaded please run "make test" then "./test" this will show you how our test cases work. Afterwards if you want to run the program fully run "make" then "./project". This is our executable where it runs the whole program and displays the BFS output in the file BFS.txt. It also runs the Floyd-Warshall and Betweeness Centriality and will print out the the distances between each node in distances.txt and the betweeness centriality values in centrality.txt

We calculated the betweeness centriality values as following: we declare one node as a source, then we find the shortest path to every other node in the dataset. For each path, every node that is in the path will increment their betweeness centriality score by 1. Then we repeat this process by making every node in the data set a source node. If two node have no connection/path than the betweeness centriality doesn't increment. This leads us to be the more connections a node has, meaning it is more central like a "hub" the higher the betweeness centriality score will be. This concept was given to us by a TA.


# **General Commands** #

**git pull** = pull the git repository

**make** = make project and will run on file "Wiki-Vote.txt" (if you want to put your own dataset change name of file in main.cpp)

**./project** = executable command in terminal...make must be run before this

**make test** = make test cases which we have made

**./test** = executable command in terminal...make test must be run before this
make clean = removes all executables