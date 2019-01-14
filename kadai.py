"""
広域システム概論I 期末レポート
J4-170175 西本洋紀 学際科学科B群2年

"""

import numpy as np

def grounded(arg):

    """
    **概要**

    grounded(arg)
        for i in arg全体の集合
            if (iが攻撃されているargの集合に含まれない)
                iは誰にも攻撃されていない主張である旨を出力
        if (誰にも攻撃されていない主張が見つからない)
            その旨を出力
    """

    no_attacked_arg_exists = False
    attacked_arg_array = arg[:,1]
    max_arg = np.amax(arg)
    list_of_no_attacked_arg = []
    for i in range(max_arg+1):
        if not i in attacked_arg_array:
            print("{}は誰にも攻撃されていない主張です。".format(i))
            no_attacked_arg_exists = True
            list_of_no_attacked_arg.append(i)
    if not no_attacked_arg_exists:
        print("誰にも攻撃されていない主張はありません。")

    return list(set(list_of_no_attacked_arg)) #次のattacked()でこのリストを再利用することを見越してのreturn

def attacked(arg):

    """
    **概要**

    attacked(arg)
        誰にも攻撃されていないargの集合のそれぞれの要素(no_attacked_arg)に対し、
            攻撃している主張の集合の中でno_attacked_argを探す(index=iだったとする)
            ->no_attacked_argは攻撃されている主張の集合のi番目の要素を攻撃していることがわかる。

    """

    list_of_no_attacked_arg=grounded(arg)
    attacking_arg_list = arg[:,0]
    attacked_arg_list = arg[:,1]
    for no_attacked_arg in list_of_no_attacked_arg:
        for i in range(len(attacking_arg_list)):
            if attacking_arg_list[i] == no_attacked_arg:
                print(no_attacked_arg,"は",attacked_arg_list[i],"を攻撃しています。")

def interactive(arg):

    """
    **概要**

    interactive(arg)
        argの攻撃している主張とされている主張を入れ替えたものを作成(arg_replace)
        arg_replace の中から攻撃している主張とされている主張の組を１つ選ぶ
            この組がargの中にもあれば、お互いに攻撃しあっている主張

    """

    interactive_args_exists =False
    arg_replace=np.zeros([len(arg),2])
    for i in range(len(arg)):
        arg_replace[i] = np.array([arg[i,1],arg[i,0]])
    for i in range(len(arg_replace)):
        if (arg[i]==arg_replace).all(axis=1).any():
            if arg[i,0]<arg[i,1]:
                print(arg[i,0],"と",arg[i,1], "は互いに攻撃しあっています。")
            interactive_args_exists = True
    if interactive_args_exists == False:
        print("互いに攻撃しあっている主張はありません。")


def conflict_free(arg):
    """
    **概要**_
    1. interactive()関数の時と同様の手順でarg_replaceを作成。
    2.主張の関係についての全てのありうる場合を求める。(all_conbination)
    3. argまたarg_replaceの中に現れる主張の組(delete_me)をall_conbinationから取り除く。
    4. 3.を終えた後にall_conbinationに残っている主張の組は、お互い攻撃してもされてもいない。

    """

    #arg_replaceの生成
    arg_replace=np.zeros([len(arg),2])
    for i in range(len(arg)):
        arg_replace[i] = np.array([arg[i,1],arg[i,0]])

    #all_conbinationの生成
    all_conbination = np.empty((0,2),int)
    for i in range(np.amax(arg)+1):
        for j in range(np.amax(arg)-i ):
            all_conbination=np.append(all_conbination,[[i,i+j+1]], axis=0)
    # print("all_conbination\n", all_conbination)

    #rgまたarg_replaceの中に現れる主張の組(delete_me)をall_conbinationから取り除く。
    for i in range(len(arg)):
        if (arg[i]==all_conbination).all(axis=1).any() \
        or (arg_replace[i]==all_conbination).all(axis=1).any():
            delete_me=[np.amin(arg[i]), np.amax(arg[i])]
            #print("delete_me", delete_me)
            #all_conbinationからdelete_meを取り除く
            for j in range(len(all_conbination)):
                #print("all_conbination\n", all_conbination)
                if (all_conbination[j]==delete_me).all():
                    all_conbination=np.delete(all_conbination, j, 0)
                    break

    #結果の出力
    if len(all_conbination)==0:
        print("お互い攻撃してもされてもいない主張はありません。\n")
    else:
        for k in range(len(all_conbination)):
            print("お互いに攻撃してもされてもいない主張は",all_conbination[k,0],"と",all_conbination[k,1],"です\n")


"""
以下では、色々な主張の集合に対して、上の関数を実行する。
"""

arg0 = np.array([[0,1],[1,2]])
arg1 = np.array([[0,1],[1,0]])
arg2 = np.array([[0,1],[1,0],[1,2],[2,1]])
arg3 = np.array([[0,1],[0,2],[0,3],[0,4],[0,5],[1,2],[1,3],[1,4],[1,5],[2,3],[2,4],[2,5],[3,4],[3,5],[4,5],\
                 [5,1],[5,2],[5,3],[5,4],[4,1],[4,2],[4,3],[3,1],[3,2],[2,1]])
arg_list = [arg0,arg1,arg2,arg3]
func = [grounded, attacked, interactive, conflict_free]
#出力結果をわかりやすく出力する関数
def show_result(arg,i):
    print("\n例"+str(i*1))
    print("arg:\n",arg)
    for i in range(4):
        print("\n"+func[i].__name__)
        func[i](arg)

#結果の出力
for i in range(4):
    show_result(arg_list[i],i)
