"""Calculates statistics, like number of algorithms in the repository and
generates a badge that can be used in the github repo.
"""

from urllib.request import Request, urlopen
from json import dumps, loads
import os

def request(url, method='GET', data=None, headers=None):
    req = Request(url, method=method, data=data, headers=headers)
    resp = urlopen(req)
    return {'code': resp.code, 'data': resp.read()}

class JsonStore:

    def __init__(self, bin_id):
        self.bin_id = bin_id
    
    def save(self, data):
        data = dumps(data).encode('utf-8')
        resp = request(
            url=self._get_url(), 
            method='PUT',
            data=data,
            headers={
                'Content-Type': 'application/json',
            })
        resp['data'] = resp['data'].decode('utf-8') if resp['data'] else ''
        if resp['code'] is not 200:
            raise Exception('Failed to store JSON data. Err code: {code}. Message: {data}'.format(**resp))
        return loads(resp['data'])
    
    def read(self):
        resp = request(
            url=self._get_url(),
            method='GET',
        )
        resp['data'] = resp['data'].decode('utf-8') if resp['data'] else ''
        if resp['code'] is not 200:
            raise Exception('Failed to fetch JSON data. Err code: {code}. Message: {data}'.format(**resp))
        return loads(resp['data'])
    
    def _get_url(self):
        return 'https://api.myjson.com/bins/{bin_id}'.format(bin_id=self.bin_id)



class Metric:

    def __init__(self, store, badge_generator):
        self.store = store
        self.badge_generator = badge_generator
    
    def calculate(self):
        value = self.do_calculate()
        self.store.save(value)
        value['data_url'] = self.store._get_url()
        self.badge_generated(self.badge_generator(value))


class CountAlgorithms(Metric):

    def __init__(self, 
                store, 
                badge_generator,
                alg_dirs=None,
                exclude_dirs=None,
                count_as_one=None):
        super(CountAlgorithms, self).__init__(store, badge_generator)
        self.alg_dirs = alg_dirs or ['.']
        self.exclude_dirs = exclude_dirs
        self.count_as_one = count_as_one
    
    def do_calculate(self):
        count = 0
        algorithms = []

        for ad in self.alg_dirs:
            cnt, algs = self._count_algorithms(ad)
            count += cnt
            algorithms += algs

        cnt, algs = self._get_cout_as_one()
        count += cnt
        algorithms += algs

        return {'count': count, 'algorithms': algorithms, 'label': '{count} Algorithms'.format(count=count)}
    
    def _count_algorithms(self, alg_dir):
        if not os.path.isdir(alg_dir):
            print('Not a directory: ', alg_dir)
            return (0, [])
        count = 0
        algorithms = []
        for root, categories, _ in os.walk(alg_dir):
            for category in categories:
                if self.exclude_dirs and category in self.exclude_dirs:
                    continue
                for _, algs, _ in os.walk(os.path.join(root, category)):
                    count += len(algs)
                    algorithms += algs
                    break
            break
        
        return (count, algorithms)

    def _get_cout_as_one(self):
        if not self.count_as_one:
            return (0, [])
        count = 0
        algorithms = []
        for d in self.count_as_one:
            if os.path.isdir(d):
                count += 1
                algorithms.append(d)
        return (count, algorithms)


    def badge_generated(self, badge):
        print('Badge Provider: ', badge['provider'])
        print('Badge URL: ', badge['url'])
        print('Markdown: ', badge['markup'])


def shieldsio_markdown_badge_generator(value):
    url = 'https://img.shields.io/badge/dynamic/json?url={data_url}&label=Algorithms&query=count'.format(**value)
    return {
        'provider': 'https://shields.io',
        'url': url,
        'markup': '[![{label}]({url})](https://github.com/ZoranPandovski/al-go-rithms)'.format(label=value['label'], url=url)
    }


def dummy_badge_gen(value):
        print(value)
    
store = JsonStore('j5r1c')

ca = CountAlgorithms(store, shieldsio_markdown_badge_generator)

ca.calculate()