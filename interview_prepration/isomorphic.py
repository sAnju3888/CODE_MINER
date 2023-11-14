    def areIsomorphic(self,str1,str2):
        if len(str1) != len(str2):
            return False
        maps = {}
        for i in range(len(str1)):
            
            #unvisited
            if str1[i] not in maps:
                
                # if value is already mapped
                if str2[i] not in maps.values():
                    maps[str1[i]] = str2[i]
                else:
                    return False
            
            else:
                #second time visiting la diff mapping checking
                if str2[i] != maps[str1[i]]:
                    return False 
        return True
                
            