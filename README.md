## get_next_line 함수란?

- `main` 함수에서 `open` 함수를 통해 파일을 읽어 들이고 `fd` 값을 할당한다.
- `open`  함수를 통해 할당 받은 `fd`값을 입력으로 함수를 실행시킨다.
- `read` 함수를 통해 `BUFFER_SIZE` 만큼씩 읽는다.
- `‘\n’` 을 발견하면 (한 줄을 읽으면) Standard Output으로 출력한다.
- 함수를 호출할 때 마다 위의 동작을 반복한다.
- 만약 다 읽거나 빈 파일일 경우 `NULL` 을 반환한다.
- 리턴한 line 값의 free는 main에서 해야한다!( or 프로그램 종료)

## 필요한 개념
File descriptor, static Variable, Linked List

## Prototype

```jsx
char    *get_next_line(int fd);
```

- `fd`,  main 함수에서 `open` 함수를 통해 할당 받은 file descriptor 값

## Return Value

- `char *line`

## Extern function

- `read` , BUFFER_SIZE 만큼씩 `open` 함수를 통해 읽어들인 파일의 문자열을 읽고 `buff`에 저장한다

## Code FlowChart

<aside>
💡 BUFF_SIZE = BUFFER_SIZE 혼동이 올 수 있지만 같은 걸로 봐주세용 ^^7

`BUFFER_SIZE`는 컴파일옵션( `-D BUFFER_SIZE=N`)을 통해 넣습니다.

`fd`값은 `main` 함수에서 `open`함수값을 받아오는 것이기 때문에

오류는 메인에서 잡거나 gnl 내부에서 잡는 두 가지 방법이 있습니다.

</aside>

![Untitled](https://github.com/AriSongYe/get_next_line/assets/82326075/26de6ac6-c9df-44ed-bf40-52f14e534229)

## 

<aside>
💡 핵심은 read_line과 join 나머지는 malloc과 free를 조심하면 된다!
</aside>

# Bonus Goal

---

> 보너스의 목적은 fd 값을 여러개 할당하면서 이전에 구현 했던 get_next_line 함수를 동일하게 구현하는 것.
> 

곧 여러개의 파일을 동시에 `open` 한뒤 할당된 fd값을 호출할 때마다

그 파일에 있는 문자열을 한 줄씩 출력하는 것이다.

## How to make?

필자는 linked list를 사용했다.

구조체를 만들어 그 안에 fd 값과 문자열을 저장할 수 있도록 했다.

```c
typedef struct s_list
{
	int				fd;
	char			*store;
	struct s_list	*next;
}	t_list;
```
