## Getting set up

If you do not have git [installed](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git), please do that first.

#### 1. Verify your Git installation

To confirm that you have git installed type in:
```
$ git --version
git version 1.9.1
```
It should respond by showing you the version of git you have installed.


#### 2. [Fork](https://help.github.com/articles/fork-a-repo/) The ENGRTeam04 Repository


Click on the button on the top that says fork.

You will now have a copy of the ENGRTeam04 repository in your profile.


#### 3. [Clone](https://help.github.com/articles/cloning-a-repository/) your fork


Click on the green dropdown button titled "Clone or download" and copy the URL there.

*Note: I recommend cloning as [SSH](https://help.github.com/articles/generating-an-ssh-key/) as it will allow you to use git without constant user authentication. If you are not comfortable with this yet, proceed with HTTPS.*

Open up your command line tool and enter:

*Note: Enter the following without the following without the angled brackets (i.e. `git clone git@github.com:YourUsername/ENGRTeam04.git`)*

```
$ cd ~
$ git clone <URL that you copied here>
Cloning into 'ENGRTeam04'...
remote: Counting objects: 874, done.
remote: Compressing objects: 100% (13/13), done.
remote: Total 874 (delta 4), reused 0 (delta 0), pack-reused 860
Receiving objects: 100% (874/874), 95.41 KiB | 0 bytes/s, done.
Resolving deltas: 100% (324/324), done.
Checking connectivity... done.
```


#### 4. Git configuration


Next we will be [configuring](https://git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup) your git setup. 


*Note: Simply replace the text inside the quotation marks with your name and email.*

```
$ cd ~/2017Challenges/
$ git config --global push.default simple
$ git config --global user.name "John Doe"
$ git config --global user.email "your_email@example.com"
$ git remote add ENGRTeam04 https://github.com/briguy-official/ENGRTeam04.git
```


#### 5. Uploading Stuff

We will be deciding in meetings on the structure we want to use for folders. 
If you are adding code for a bonus, add it in the folder for that set of bonus
activities (i.e. C4, etc). 



#### 6. Submitting Your Code

Assuming you are in the directory you are updating, you will enter the following
```
$ git add ./*
$ git commit -m "Title representing the changes made"
$ git pull ENGRTeam04 master
$ git push origin master
```

*Note: Replace the text inside the quotations with the relevant information.*

If you go to the page where your forked repository is contained your updated code should be there. 

Click on the "New pull request" button to submit your code for review. 

#### 7. Thank you
This read me was borrowed and modified from [The year of programming challenge](https://github.com/YearOfProgramming/2017Challenges)

