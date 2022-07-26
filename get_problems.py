from asyncore import write
from multiprocessing.connection import wait
import requests 
import os
import shutil
import time
from bs4 import BeautifulSoup

# shutil.rmtree("./problems")
# os.mkdir("./problems")

start = 1
end = 101

for y in range (1, 9):
    
    subset_dir = f"./problems/{start}-{end}/"
    os.mkdir(subset_dir)

    for x in range (start, end): 
        time.sleep(1)
        problem_dir = subset_dir + f"{x}"
        solution_dir = problem_dir + "/solution/"
        # make directory for problems
        os.mkdir(problem_dir)

        url = f"https://projecteuler.net/problem={x}/"
        r = requests.get(url)
        htmlContent = r.content
        soup = BeautifulSoup(htmlContent,'html.parser')
        title = soup.find("h2")
        content = soup.find("div",class_="problem_content")

        print(x)
        print(title.get_text())
        print(content.get_text())

        # f= open(f"{problem_dir}/problem-{x}.md","w+")
        # write_content = f"# Problem {x}\n\n## {title.get_text()}\n{content.get_text()}"
        # f.write(write_content)
        # f.close()

        f= open(f"{problem_dir}/problem-{x}.c","w+")
        c_template = """/****************************************
 * Author: milan-stoj
 * Problem: %d
 * Title: %s
 * Description:
 * %s 
 *
 * Answer: 
 ************************************/

#include <stdio.h>
int main() {
    printf("Hello, Euler!");
    return 0;
}
""" % (x, title.get_text(), '\n * \t'.join(content.get_text().splitlines()))
        f.write(c_template)
        f.close()

    start = end
    end += 100