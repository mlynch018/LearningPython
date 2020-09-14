hyps = [ '((not m) and c) <= (not h)','(not c) <= (not m) or (not h)']
concl = ['m<=c']
fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^10s}|{4:^10s}|{5:^8s}|"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^10d}|{4:^10d}|{5:^8d}|"
div = "---+---+---+----------+--------+----------+"
print(fst.format('c','h','m','m\'&c=>h\'', 'c\'=>m\'|h\'', 'm=>c'))

for c in range(2):
   for h in range(2):
       for m in range(2):
            print(div)
            print(fst2.format(c,h,m,eval(hyps[0]),eval(hyps[1]),eval(concl[0])))



