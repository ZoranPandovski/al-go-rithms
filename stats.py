"""Calculates the number of algorithms contributed to this repository.
"""

from abc import abstractmethod
from urllib.request import Request, urlopen
from json import dumps, loads
import os

def request(url, method='GET', data=None, headers=None):
    """Wrapper for urllib.urlopen that performs HTTP requests.

    Returns dict with the result code and the data read from the remote server.
    """
    req = Request(url, method=method, data=data, headers=headers)
    resp = urlopen(req)
    return {'code': resp.code, 'data': resp.read()}

class JsonStore:
    """Store for saving and retrieval of JSON objects.

    Ideally the JSON would be stored on a remote server and made available on
    a specific URL.

    Parameters:
        bin_id - the ID of the remote json key (bin id).
    """
    def __init__(self, bin_id):
        self.bin_id = bin_id

    def save(self, data):
        """Stores the given data on a remote server.
        """
        data = dumps(data).encode('utf-8')
        resp = request(
            url=self.get_url(),
            method='PUT',
            data=data,
            headers={
                'Content-Type': 'application/json',
            })
        resp['data'] = resp['data'].decode('utf-8') if resp['data'] else ''
        if resp['code'] != 200:
            raise Exception('Failed to store JSON data. ' +
                            'Err code: {code}. Message: {data}'.format(**resp))
        return loads(resp['data'])

    def read(self):
        """Reads the data from the remote server.
        """
        resp = request(
            url=self.get_url(),
            method='GET',
        )
        resp['data'] = resp['data'].decode('utf-8') if resp['data'] else ''
        if resp['code'] != 200:
            raise Exception('Failed to fetch JSON data. ' +
                            'Err code: {code}. Message: {data}'.format(**resp))
        return loads(resp['data'])

    def get_url(self):
        """Returns the data URL.
        """
        return 'https://api.myjson.com/bins/{bin_id}'.format(bin_id=self.bin_id)



class Metric:
    """Calculates some metric on the given repository.

    The calculated data is stores as JSON in the given JsonStore.
    Once the metric data is calculated and stored, a badge would be generated
    with the calculated values.

    Params:
        store - the JsonStore in which to store the metric data.
        badge_generator - function to generate the badge data. The badge_calculator
        signature looks like this:

            def badge_calculator(value):
                return {
                    'provider': 'string, the name of the badge provider',
                    'url': 'string, the URL of the badge image',
                    'markup': 'string, generated markup to use in documents'
                }
    """
    def __init__(self, store, badge_generator):
        self.store = store
        self.badge_generator = badge_generator

    def calculate(self):
        """Calculates the metrics data, then stores and generates the badge.
        """
        value = self.do_calculate()
        self.store.save(value)
        value['data_url'] = self.store.get_url()
        self.badge_generated(self.badge_generator(value))

    @abstractmethod
    def do_calculate(self):
        """Performs the actual calculation of the metric data.
        The return result must be a dict containing 'data_url' - URL to the
        remote JSON data from the store.
        """
        pass

    @abstractmethod
    def badge_generated(self, badge):
        """Called after the metric data has been calculated and the badge data is
        generated.
        """
        pass


class CountAlgorithms(Metric):
    """Is a Metric calculator that calculates the number of different algorithms
    in this repository.

    This metric assumes that the repository follows a general pattern in the
    file structure:

        <Algorithm Category> +
                            <Algorithm Name> +
                                            <Language 1>
                                            <Language 2>

    The algorithm for counting the number of algorithms walks the given directory
    that contain the algorithm categories. Then for each category (which is a
    directory itself), lists the sub directories, which represent the names of
    the algorithms for that category. The algorithms are collected and counted.

    If some of the directories do not contain algorithms implementations, then
    they can be skipped by setting the 'exclude_dirs' property.

    Some of the top level directories may contain implementations of algorithms
    themselves (do not follow the general structure of the repository). They may
    be specified with the property 'count_as_one' and will be counted as a single
    algorithm.

    Params:
        store - the JsonStore in which to save the algorithms count data.
        badge_generator - generates the badge.
        alg_dirs - list of directories that contain the algorithm categories (for
                    example the root directory of this repository).
        exclude_dirs - list of directories to exclude from the count.
        count_as_one - list of directories that contain algorithm implementation
                       and will be counted as one.
    """
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
        """Counts the algorithms.
        """
        count = 0
        algorithms = []

        for alg_dir in self.alg_dirs:
            cnt, algs = self._count_algorithms(alg_dir)
            count += cnt
            algorithms += algs

        cnt, algs = self._get_cout_as_one()
        count += cnt
        algorithms += algs

        return {
            'count': count,
            'algorithms': algorithms,
            'label': '{count} Algorithms'.format(count=count)
        }

    def _count_algorithms(self, alg_dir):
        """Counts the algorithms for the given alg_dir only.
        """
        if not os.path.isdir(alg_dir):
            print('Not a directory: ', alg_dir)
            return (0, [])
        count = 0
        algorithms = []
        for root, categories, _ in os.walk(alg_dir):
            for category in categories:
                if self.exclude_dirs and category in self.exclude_dirs:
                    continue
                if self.count_as_one and category in self.count_as_one:
                    continue
                for _, algs, _ in os.walk(os.path.join(root, category)):
                    count += len(algs)
                    algorithms += algs
                    break
            break

        return (count, algorithms)

    def _get_cout_as_one(self):
        """Count the algorithms in the directories that do not follow the general
        repo structure.
        """
        if not self.count_as_one:
            return (0, [])
        count = 0
        algorithms = []
        for alg in self.count_as_one:
            if os.path.isdir(alg):
                count += 1
                algorithms.append(alg)
        return (count, algorithms)


    def badge_generated(self, badge):
        """Prints out the generated badge and markup for it.
        """
        print('Badge Provider: ', badge['provider'])
        print('Badge URL: ', badge['url'])
        print('Markdown: ', badge['markup'])
        print()
        print('If you haven\'t already, you can now add ' +
              'the following snippet to your README file:')
        print()
        print('\t', badge['markup'])


def shieldsio_markdown_badge_generator(badge_label=None,
                                       badge_hover=None,
                                       badge_link=None,
                                       metric='count',
                                       badge_color=None,
                                       badge_style='flat-square'):
    """Generates badge generator for a badge hosted on shields.io.

    Params:
        badge_label - the label in the badge itself. For example "algorithms".
                      this label is displayed in the left box of the badge.
        badge_hover - the hover text displayed when going over the badge. Used
                      in the Markdown markup for the badge.
        badge_link - the link of the badge (in the markup).
        metric - the name of the property in the saved JSON that contains the
                 data that should be displayed in the right box of the badge.
        badge_color - the color of the badge.
        badge_style - badge style. May be: 'plastic', 'flat', 'flat-square'.
    """
    def _get_badge_url(data_url):
        url = 'https://img.shields.io/badge/dynamic/json?'
        params = {
            'label': badge_label,
            'query': metric,
            'url': data_url,
            'color': badge_color,
            'style': badge_style,
        }
        for param, value in params.items():
            if value is not None:
                url += '&' + '{key}={value}'.format(key=param, value=value)
        return url

    def _get_markup(hover, badge_url):
        hover = badge_hover or hover
        return '[![{hover}]({badge_url})]({badge_link})'.format(
            hover=hover,
            badge_url=badge_url,
            badge_link=badge_link)

    def _generator(value):
        url = _get_badge_url(value['data_url'])
        return {
            'provider': 'https://shields.io',
            'url': url,
            'markup': _get_markup(hover=value['label'], badge_url=url)
        }

    return _generator


def get_parser():
    """Sets up an arguments parser for the script's CLI.
    """
    from argparse import ArgumentParser

    parser = ArgumentParser(description='Calculates statistics and metrics ' +
                            'like number of algorithms.')

    # JSON Store
    parser.add_argument('--json-key',
                        dest='json_key_id',
                        required=True,
                        help='JSON key id / bin id for the remote JSON object.')

    # Badge config
    parser.add_argument('--badge-color',
                        dest='badge_color',
                        default=None,
                        help='Badge label color.')
    parser.add_argument('--badge-style',
                        dest='badge_style',
                        default='flat-square',
                        help='Badge style. Available: plastic, flat, ' +
                        'flat-square, for-the-badge and social.')
    parser.add_argument('--badge-label',
                        dest='badge_label',
                        default=None,
                        help='Badge label.')
    parser.add_argument('--badge-hover',
                        dest='badge_hover',
                        default=None,
                        help='Badge hover. Shown on mouse hover over the label.')
    parser.add_argument('--badge-link',
                        dest='badge_link',
                        default=None,
                        help='Badge link.')


    # Algorithms counter
    parser.add_argument('-d', '--directory',
                        nargs='+',
                        dest='dirs',
                        default='.',
                        help='Examine directories.')
    parser.add_argument('-e', '--exclude',
                        nargs='+',
                        dest='exclude',
                        default=None,
                        help='Exclude these directories.')
    parser.add_argument('-o', '--count-as-one',
                        nargs='+',
                        dest='as_one',
                        default=None,
                        help='Count these directories as just one algorithm.')

    return parser


def run_stats():
    """Runs the script.
    """
    parser = get_parser()

    args = parser.parse_args()

    store = JsonStore(args.json_key_id)

    metric = CountAlgorithms(store=store,
                             badge_generator=shieldsio_markdown_badge_generator(
                                 badge_label=args.badge_label,
                                 badge_hover=args.badge_hover,
                                 badge_link=args.badge_link,
                                 badge_color=args.badge_color,
                                 badge_style=args.badge_style,
                                 metric='count',
                             ),
                             alg_dirs=args.dirs,
                             exclude_dirs=args.exclude,
                             count_as_one=args.as_one)

    metric.calculate()

if __name__ == '__main__':
    run_stats()
