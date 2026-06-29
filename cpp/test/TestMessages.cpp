#include "cucumber/messages/envelope.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

namespace
{
    std::vector<std::tuple<std::string, std::size_t, nlohmann::json>> GetTestData()
    {
        std::vector<std::tuple<std::string, std::size_t, nlohmann::json>> jsonMessages;

        const auto* testdata = CUCUMBER_MESSAGES_TESTDATA_FOLDER;

        for (const auto& file : std::filesystem::directory_iterator(testdata))
        {
            if (file.is_regular_file() && (file.path().extension() == ".ndjson"))
            {
                std::size_t lineNr = 1;
                std::ifstream ifstream{ file.path() };
                for (std::string line; std::getline(ifstream, line); ++lineNr)
                {
                    jsonMessages.emplace_back(std::filesystem::absolute(file.path()).string(), lineNr, nlohmann::json::parse(line));
                }
            }
        }

        return jsonMessages;
    }

    class TestMessages : public ::testing::Test
    {
    public:
        explicit TestMessages(nlohmann::json jsonMessage)
            : jsonMessage(std::move(jsonMessage))
        {}

    protected:
        [[nodiscard]] const nlohmann::json& JsonMessage() const
        {
            return jsonMessage;
        }

    private:
        nlohmann::json jsonMessage;
    };

    class RuntimeMessageTest : public TestMessages
    {
    public:
        explicit RuntimeMessageTest(nlohmann::json jsonMessage)
            : TestMessages(std::move(jsonMessage))
        {}

    private:
        void TestBody() override
        {
            const auto& message = JsonMessage();

            cucumber::messages::envelope envelope;
            envelope.from_json(message);

            nlohmann::json serializedJson{};
            envelope.to_json(serializedJson);

            ASSERT_THAT(serializedJson, ::testing::Eq(message));
        }
    };

    const volatile auto loadTests = []()
    {
        std::unordered_map<std::string, size_t> nameCounts;

        for (auto& [file, line, jsonMessage] : GetTestData())
        {
            auto testName = jsonMessage.begin().key();
            const auto count = ++nameCounts[testName];

            if (count > 1)
            {
                testName += "_" + std::to_string(count);
            }

            ::testing::RegisterTest("TestMessages", testName.c_str(), nullptr, nullptr, file.c_str(), static_cast<int>(line),
                [jsonMessage = std::move(jsonMessage)]() -> RuntimeMessageTest*
                {
                    return new RuntimeMessageTest(jsonMessage); // NOLINT(cppcoreguidelines-owning-memory)
                });
        }

        return true;
    }();
}
