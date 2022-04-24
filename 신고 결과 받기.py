def solution(id_list, report, k):
    answer = []
    
    report_dict = dict()
    
    for r in report:
        report_set = r.split()
        if report_set[1] not in report_dict.keys():
            report_dict[report_set[1]] = set()
        report_dict[report_set[1]].add(report_set[0])
    
    answer = [0]*len(id_list)
    
    for id in report_dict:
        if len(report_dict[id]) >= k:
            for name in report_dict[id]:
                answer[id_list.index(name)] += 1    
    
    return answer