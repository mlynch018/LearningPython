hyps = [ '(p and r) <= q', 'r or (not q)', 'q <= p']
concl = ['(p and q) <= r']
fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^10s}|{4:^8s}|{5:^8s}|{6:^10s}|"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^10d}|{4:^8d}|{5:^8d}|{6:^10d}|"
div = "---+---+---+----------+--------+--------+----------+"
print(fst.format('p','q','r','(p&r)=>q', 'rv\'q', 'q=>p','(p&q)=>r'))

for p in range(2):
   for q in range(2):
       for r in range(2):
            print(div)
            print(fst2.format(p,q,r,eval(hyps[0]),eval(hyps[1]),eval(hyps[2]),eval(concl[0])))
