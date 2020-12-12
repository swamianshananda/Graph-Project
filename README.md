# khattri2-anshcs2-tyxia2

Link to presentation used in video https://docs.google.com/presentation/d/1zmGBXCm43ChIfUwAg9eAY0T8a443mNOmMLy1p3ydWZs/edit?usp=sharing

Link to Final Presentation Video https://illinois.zoom.us/rec/share/xGrq34MKg9K1rzH1sdj__gAmM26Jm44VG2e2hSQr1vq8zp9NmMB4f6VwVoWNb7ty.RNE8sqyqJoHo_mD8 



# **INTRODUCTION** #

Hello!!! We are Ansh Shah, Neel Khattri, and Taylor Xia, and this is our cs225 final project. For our final project we are using a twitter sub data set, and are modeling it so that we have incoproated Floyd-Warshall's shortest path algorithim, and also a Betweenness Centrality calculation. 

# **PURPOSE** #

We are running the Floyd-Warshall algorithm to find the shortest number of connections between two nodes. This way two users can use the least amount of work to figure out how they knew each other. We are running a Betweenness Centrality calculation to show how "popular" or "connected" someone is based of their Betweenness Centrality value.

# **INSTRUCTIONS** #

The data set we have used is called twitter_combined.txt. However due to that data being too large...we are using another data called "Wiki-Vote.txt" as concept of proof. The format is as follows

123456789 987654321 <br />
12345 54931 <br />
12443241 54254354 <br />
...
<br />
The number in the left hand column is a user ID of type unsigned long. Then there is a space. The number in the right column is a differnet user ID of type unsigned long. NO SPACES after that it is a new line. Each line represents a DIRECTED connection, in this case... user with userId 123456789 follows user with userId 987654321. The left column follows the right column. This is a list of connections is what our dataset is. If you would like to use a different dataset of the same format, go into the main.cpp file and switch the "Wiki-Vote.txt" to the name of the txt file with the SAME DATA FORMAT.

<br />
HERE IS A LINK TO OUR DATASET *: http://snap.stanford.edu/data/ego-Twitter.html<br />
*please note that we used the twitter_combined.txt.gz file and then switched/converted it to a txt file (by switching the file ending) where it listed out the connections as seen above. We did this because no computers/applications we had to could read the format, and we confirmed it with our TA Alex Shi who said it was good.

<br />
<br />
We have provided test cases. Once downloaded please run "make test" then "./test" this will show you how our test cases work. Afterwards if you want to run the program fully run "make" then "./project". This is our executable where it runs the whole program and displays the BFS output in the file "BFS.txt". It also runs the Floyd-Warshall and Betweenness Centrality and will print out the the distances between each node in "distances.txt" and the Betweenness Centrality values in "centrality.txt".

<br />
<br />

We calculated the Betweenness Centrality values as following: using a Brandes algorithm that allows us to perform a BFS search to figure out the shortest path, then marking all the nodes in the shortest path between a source node and every other node in the dataset. We repeated this by making every node in the dataset a source node.

We used the pseudo code of a Brandes algorithm from this source
https://www.cl.cam.ac.uk/teaching/1718/MLRD/handbook/brandes.html
*we confirmed it was correct by testing with online examples, and this was the same method that the TA explained to us in office hours

# **General Commands** #

**git pull** = pull the git repository

**make** = make project and will run on file "Wiki-Vote.txt" (if you want to put your own dataset change name of file in main.cpp)

**./project** = executable command in terminal...make must be run before this

**make test** = make test cases which we have made

**./test** = executable command in terminal...make test must be run before this
make clean = removes all executables


