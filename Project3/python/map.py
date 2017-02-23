# Python program to find path between 
# landing zone and antenna drop zones
#
# ENGR 14200 project 3
# Spring 2017
# Team 04 / Brian Acosta
# last revised: 02/20/2017
#
from math import sqrt

# helper static function for the Map constructor
def buffer(arr, rad, coord):
    for r in range(len(arr)):
        for c in range(len(arr[0])):
            dist = sqrt((r - coord[0]) ** 2 + (c - coord[1]) ** 2)
            if ((arr[r][c] != 5 and arr[r][c] != 40) and dist < rad):
                arr[r][c] = 5
    return arr
    
class Map:
    
    def __init__(self, mapfile):
    
        ########################################################################
        ## INITIALIZE A MAP FROM FILE AND ADD A BUFFER TO IT
        ########################################################################
        self.bufferRadius = 15                  # measured in cm 
        self.rawMap = []                        # map given by instruction team
        self.bufferMap = []                     # map that point representation
                                                # of alv can safely follow
        self.tags = [0, 40, 5]                  # map values w/ special meaning
         
        # input the raw map from a text file 
        with open(mapfile) as map:
            tempmap = map.readlines()
        
        # split the raw map into a matrix 
        for line in tempmap:
            self.rawMap.append(line.split())
        
        # cast values to int
        for row in range(len(self.rawMap)):
            for col in range(len(self.rawMap[0])):
                self.rawMap[row][col] = int(self.rawMap[row][col])
        
        # create buffer so that nxt does not run into obstacles
        
        # NOTE: I'm sure there is a faster way to initialize this thing but we 
        # only need to do it once, so it's worth it to have code that gives a 
        # better idea of what's going on
        self.bufferMap = self.rawMap[:]
        
        for row in range(len(self.bufferMap)):
            for col in range(len(self.bufferMap[0])):
                if not (self.bufferMap[row][col] in self.tags):
                    self.bufferMap = buffer(self.bufferMap, self.bufferRadius, [row, col])
                    
        
        ########################################################################
        ## SET UP COORDINATE SYSTEM
        ########################################################################
        
        self.xLen = len(self.bufferMap[0]);
        self.yLen = len(self.bufferMap[0]);
        
                    
    def getVal(self, x, y):
        #TODO: finish this