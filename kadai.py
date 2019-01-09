import numpy as np

def grounded(arg):
    no_attacked_arg_exists = False
    attacked_arg = arg[:,1]
    max_arg = np.amax(arg)
    list_of_no_attacked_arg = []
    for i in range(max_arg+1):
        if not i in attacked_arg:
            print("{}は誰にも攻撃されていない主張です。".format(i))
            no_attacked_arg_exists = True
            list_of_no_attacked_arg.append(i)
    if not no_attacked_arg_exists:
        print("誰にも攻撃されていない主張はありません")

    return list(set(list_of_no_attacked_arg))

def attacked(arg):
    list_of_no_attacked_arg=grounded(arg)
    attacking_arg_list = arg[:,0]
    attacked_arg_list = arg[:,1]
    for no_attacked_arg in list_of_no_attacked_arg:
        for i in range(len(attacking_arg_list)):
            if attacking_arg_list[i] == no_attacked_arg:
                print(no_attacked_arg,"は",attacked_arg_list[i],"を攻撃しています。")

def interactive(arg):
    interactive_args_exists =False
    arg_replace=np.zeros([len(arg),2])
    for i in range(len(arg)):
        arg_replace[i] = np.array([arg[i,1],arg[i,0]])
    for i in range(len(arg_replace)):
        if (arg[i]==arg_replace).all(axis=1).any():
            print(arg[i,0],"と",arg[i,1], "は互いに攻撃しあっています。")
            interactive_args_exists = True
    if interactive_args_exists == False:
        print("互いに攻撃しあっている主張はありません")
def conflict_free(arg):
    arg_replace=np.zeros([len(arg),2])
    for i in range(len(arg)):
        arg_replace[i] = np.array([arg[i,1],arg[i,0]])
    all_conbination = np.empty((0,2),int)
    for i in range(len(arg)):
        for j in range(len(arg)-i -1):
            all_conbination=np.append(all_conbination,[[i,i+j+1]], axis=0)
    for i in range(len(arg)):
        if (arg[i]==all_conbination).all(axis=1).any() or (arg_replace[i]==all_conbination).all(axis=1).any():
            delete_me=np.array([[np.amax(arg[i]), np.amin(arg[i])]])
            if delete_me in all_conbination:
                all_conbination=np.delete(all_conbination,delete_me,axis=0)
    if len(all_conbination)==0:
        print("お互い攻撃してもされてもいない主張はありません")
    else:
        for k in range(len(all_conbination)):
            print("お互いに攻撃してもされてもいない主張は",all_conbination[k,0],"と",all_conbination[k,1],"です")

print("")
print("例1")
arg1 = np.array([[0,1],[1,2]])
print(arg1)
print("grounded")
grounded(arg1)
print("")
print("attacked")
attacked(arg1)
print("")
print("interactive")
interactive(arg1)
print("")
print("conflict_free")
conflict_free(arg1)

print("")
print("例2")
arg2 = np.array([[0,1],[1,0]])
print(arg2)
print("grounded")
grounded(arg2)
print("")
print("attacked")
attacked(arg2)
print("")
print("interactive")
interactive(arg2)
print("")
print("conflict_free")
conflict_free(arg2)

print("")
print("例3")
arg3 = np.array([[0,1],[1,0],[1,2],[2,1]])
print(arg3)
print("grounded")
grounded(arg3)
print("")
print("attacked")
attacked(arg3)
print("")
print("interactive")
interactive(arg3)
print("")
print("conflict_free")
conflict_free(arg3)
