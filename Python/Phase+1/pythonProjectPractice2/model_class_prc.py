# This code parses date/times, so please
#
#     pip install python-dateutil
#
# To use this code, make sure you
#
#     import json
#
# and then, to convert JSON from a string, do
#
#     result = iris_from_dict(json.loads(json_string))

from dataclasses import dataclass
from typing import Optional, Any, List, TypeVar, Type, cast, Callable
from datetime import datetime
import dateutil.parser


T = TypeVar("T")


def from_str(x: Any) -> str:
    assert isinstance(x, str)
    return x


def from_none(x: Any) -> Any:
    assert x is None
    return x


def from_union(fs, x):
    for f in fs:
        try:
            return f(x)
        except:
            pass
    assert False


def from_datetime(x: Any) -> datetime:
    return dateutil.parser.parse(x)


def to_class(c: Type[T], x: Any) -> dict:
    assert isinstance(x, c)
    return cast(Any, x).to_dict()


def from_int(x: Any) -> int:
    assert isinstance(x, int) and not isinstance(x, bool)
    return x


def from_list(f: Callable[[Any], T], x: Any) -> List[T]:
    assert isinstance(x, list)
    return [f(y) for y in x]


@dataclass
class Source:
    name: str
    id: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Source':
        assert isinstance(obj, dict)
        name = from_str(obj.get("name"))
        id = from_union([from_none, from_str], obj.get("id"))
        return Source(name, id)

    def to_dict(self) -> dict:
        result: dict = {}
        result["name"] = from_str(self.name)
        result["id"] = from_union([from_none, from_str], self.id)
        return result


@dataclass
class Article:
    source: Source
    title: str
    description: str
    url: str
    published_at: datetime
    content: str
    author: Optional[str] = None
    url_to_image: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Article':
        assert isinstance(obj, dict)
        source = Source.from_dict(obj.get("source"))
        title = from_str(obj.get("title"))
        description = from_str(obj.get("description"))
        url = from_str(obj.get("url"))
        published_at = from_datetime(obj.get("publishedAt"))
        content = from_str(obj.get("content"))
        author = from_union([from_none, from_str], obj.get("author"))
        url_to_image = from_union([from_none, from_str], obj.get("urlToImage"))
        return Article(source, title, description, url, published_at, content, author, url_to_image)

    def to_dict(self) -> dict:
        result: dict = {}
        result["source"] = to_class(Source, self.source)
        result["title"] = from_str(self.title)
        result["description"] = from_str(self.description)
        result["url"] = from_str(self.url)
        result["publishedAt"] = self.published_at.isoformat()
        result["content"] = from_str(self.content)
        result["author"] = from_union([from_none, from_str], self.author)
        result["urlToImage"] = from_union([from_none, from_str], self.url_to_image)
        return result


@dataclass
class Iris:
    status: str
    total_results: int
    articles: List[Article]

    @staticmethod
    def from_dict(obj: Any) -> 'Iris':
        assert isinstance(obj, dict)
        status = from_str(obj.get("status"))
        total_results = from_int(obj.get("totalResults"))
        articles = from_list(Article.from_dict, obj.get("articles"))
        return Iris(status, total_results, articles)

    def to_dict(self) -> dict:
        result: dict = {}
        result["status"] = from_str(self.status)
        result["totalResults"] = from_int(self.total_results)
        result["articles"] = from_list(lambda x: to_class(Article, x), self.articles)
        return result


def iris_from_dict(s: Any) -> Iris:
    return Iris.from_dict(s)


def iris_to_dict(x: Iris) -> Any:
    return to_class(Iris, x)
