
//https://modoocode.com/269
//���� 1
//�Ǻ���ġ ������ ��Ƽ �������� Ȱ���ؼ� ������ ����� �� �ִ� ����� ������� ?
class TKApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		std::vector<std::thread> threads;
		int n(12);
		std::vector<int> table(n + 1, 0);

		if (n >= 1) table[1] = 1;
		if (n >= 2) table[2] = 1;

		for (int i(1); i <= 2; i++)
		{
			threads.push_back(std::thread([&table, n, i]
				{
					for (int j(3); j <= (n - i); j++)
					{
						if (table[j])
							continue;

						table[j] = table[j - 2] + table[j - 1];
					}

					CString message;

					message.Format(CString("Thread[%d] result: %d\n"), i, table[n - i]);
					OutputDebugString(message);
				}
			));
		}

		for (int i(0); i < 2; i++)
			threads[i].join();

		int result(table[n - 2] + table[n - 1]);
		CString resultMessage;

		resultMessage.Format(CString("Result: %d\n"), result);
		OutputDebugString(resultMessage);

		return TRUE;
	}
};

TKApp theApp;
//windows mfc ������ ���� �����Ǿ����ϴ�.